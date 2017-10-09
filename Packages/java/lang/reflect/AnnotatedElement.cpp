//
//  AnnotatedElement.cpp
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "AnnotatedElement.hpp"
#include "Class.hpp"
#include "Annotation.hpp"

using namespace java::lang;
using namespace java::lang::reflect;

AnnotatedElement::AnnotatedElement(JVM* jvm) : Object()
{
    
}

AnnotatedElement::AnnotatedElement(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/reflect/AnnotatedElement;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

AnnotatedElement::~AnnotatedElement()
{
    
}

bool AnnotatedElement::isAnnotationPresent(Class annotatedClass)
{
    jmethodID isAnnotationPresentMethod = this->vm->GetMethodID(this->cls, "isAnnotationPresent", "(Ljava/lang/Class;)Z");
    return this->vm->CallBooleanMethod(this->inst, isAnnotationPresentMethod, annotatedClass.ref().get());
}

Annotation AnnotatedElement::getAnnotation(Class annotatedClass)
{
    jmethodID getAnnotationMethod = this->vm->GetMethodID(this->cls, "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation");
    return Annotation(this->vm, this->vm->CallObjectMethod(this->inst, getAnnotationMethod, annotatedClass.ref().get()));
}

Array<Annotation> AnnotatedElement::getAnnotations()
{
    jmethodID getAnnotationsMethod = this->vm->GetMethodID(this->cls, "getAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return Array<Annotation>(this->vm, this->vm->CallObjectMethod(this->inst, getAnnotationsMethod));
}

Array<Annotation> AnnotatedElement::getAnnotationsByType(Class annotatedClass)
{
    jmethodID getAnnotationsByTypeMethod = this->vm->GetMethodID(this->cls, "getAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;");
    return Array<Annotation>(this->vm, this->vm->CallObjectMethod(this->inst, getAnnotationsByTypeMethod, annotatedClass.ref().get()));
}

Annotation AnnotatedElement::getDeclaredAnnotation(Class annotatedClass)
{
    jmethodID getDeclaredAnnotationMethod = this->vm->GetMethodID(this->cls, "getDeclaredAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return Annotation(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredAnnotationMethod, annotatedClass.ref().get()));
}

Array<Annotation> AnnotatedElement::getDeclaredAnnotationsByType(Class annotatedClass)
{
    jmethodID getDeclaredAnnotationsByTypeMethod = this->vm->GetMethodID(this->cls, "getDeclaredAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;");
    return Array<Annotation>(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredAnnotationsByTypeMethod, annotatedClass.ref().get()));
}

Array<Annotation> AnnotatedElement::getDeclaredAnnotations()
{
    jmethodID getDeclaredAnnotationsMethod = this->vm->GetMethodID(this->cls, "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return Array<Annotation>(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredAnnotationsMethod));
}
