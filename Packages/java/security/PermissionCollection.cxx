//
//  PermissionCollection.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "PermissionCollection.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "Permission.hxx"
#include "Enumeration.hxx"

using java::security::PermissionCollection;
using java::lang::Object;
using java::lang::String;
using java::security::Permission;
using java::util::Enumeration;


PermissionCollection::PermissionCollection(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/security/PermissionCollection;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

PermissionCollection::PermissionCollection(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/security/PermissionCollection;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

void PermissionCollection::add(Permission permission)
{
    static jmethodID addMethod = this->vm->GetMethodID(this->cls.get(), "add", "(Ljava/security/Permission;)V");
    this->vm->CallVoidMethod(this->inst.get(), addMethod, permission.ref().get());
}

Enumeration<Permission> PermissionCollection::elements()
{
    static jmethodID elementsMethod = this->vm->GetMethodID(this->cls.get(), "elements", "()Ljava/util/Enumeration;");
    return Enumeration<Permission>(this->vm, this->vm->CallObjectMethod(this->inst.get(), elementsMethod));
}

bool PermissionCollection::implies(Permission permission)
{
    static jmethodID impliesMethod = this->vm->GetMethodID(this->cls.get(), "implies", "(Ljava/security/Permission;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), impliesMethod, permission.ref().get());
}

bool PermissionCollection::isReadOnly()
{
    static jmethodID isReadOnlyMethod = this->vm->GetMethodID(this->cls.get(), "isReadOnly", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isReadOnlyMethod);
}

void PermissionCollection::setReadOnly()
{
    static jmethodID setReadOnlyMethod = this->vm->GetMethodID(this->cls.get(), "setReadOnly", "()V");
    this->vm->CallVoidMethod(this->inst.get(), setReadOnlyMethod);
}

String PermissionCollection::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
