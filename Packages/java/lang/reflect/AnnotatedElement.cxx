//
//  AnnotatedElement.cxx
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "AnnotatedElement.hxx"
#include "Class.hxx"
#include "Annotation.hxx"

using java::lang::Annotation;
using java::lang::reflect::AnnotatedElement;

AnnotatedElement::AnnotatedElement(JVM* jvm) : Object()
{
    
}

AnnotatedElement::AnnotatedElement(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/AnnotatedElement;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

bool AnnotatedElement::isAnnotationPresent(Class annotatedClass)
{
    jmethodID isAnnotationPresentMethod = this->vm->GetMethodID(this->cls.get(), "isAnnotationPresent", "(Ljava/lang/Class;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAnnotationPresentMethod, annotatedClass.ref().get());
}

Annotation AnnotatedElement::getAnnotation(Class annotatedClass)
{
    jmethodID getAnnotationMethod = this->vm->GetMethodID(this->cls.get(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation");
    return Annotation(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAnnotationMethod, annotatedClass.ref().get()));
}

Array<Annotation> AnnotatedElement::getAnnotations()
{
    jmethodID getAnnotationsMethod = this->vm->GetMethodID(this->cls.get(), "getAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return Array<Annotation>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAnnotationsMethod));
}

Array<Annotation> AnnotatedElement::getAnnotationsByType(Class annotatedClass)
{
    jmethodID getAnnotationsByTypeMethod = this->vm->GetMethodID(this->cls.get(), "getAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;");
    return Array<Annotation>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAnnotationsByTypeMethod, annotatedClass.ref().get()));
}

Annotation AnnotatedElement::getDeclaredAnnotation(Class annotatedClass)
{
    jmethodID getDeclaredAnnotationMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return Annotation(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDeclaredAnnotationMethod, annotatedClass.ref().get()));
}

Array<Annotation> AnnotatedElement::getDeclaredAnnotationsByType(Class annotatedClass)
{
    jmethodID getDeclaredAnnotationsByTypeMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;");
    return Array<Annotation>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDeclaredAnnotationsByTypeMethod, annotatedClass.ref().get()));
}

Array<Annotation> AnnotatedElement::getDeclaredAnnotations()
{
    jmethodID getDeclaredAnnotationsMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    return Array<Annotation>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDeclaredAnnotationsMethod));
}
