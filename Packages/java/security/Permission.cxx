//
//  Permission.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Permission.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "PermissionCollection.hxx"

using java::security::Permission;
using java::lang::Object;
using java::lang::String;
using java::security::PermissionCollection;


Permission::Permission(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/security/Permission;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Permission::Permission(JVM* vm, String name) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/security/Permission;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, name.ref().get()));
    }
}

void Permission::checkGuard(Object object)
{
    static jmethodID checkGuardMethod = this->vm->GetMethodID(this->cls.get(), "checkGuard", "(Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), checkGuardMethod, object.ref().get());
}

bool Permission::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

String Permission::getActions()
{
    static jmethodID getActionsMethod = this->vm->GetMethodID(this->cls.get(), "getActions", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getActionsMethod));
}

String Permission::getName()
{
    static jmethodID getNameMethod = this->vm->GetMethodID(this->cls.get(), "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getNameMethod));
}

std::int32_t Permission::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool Permission::implies(Permission permission)
{
    static jmethodID impliesMethod = this->vm->GetMethodID(this->cls.get(), "implies", "(Ljava/security/Permission;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), impliesMethod, permission.ref().get());
}

PermissionCollection Permission::newPermissionCollection()
{
    static jmethodID newPermissionCollectionMethod = this->vm->GetMethodID(this->cls.get(), "newPermissionCollection", "()Ljava/security/PermissionCollection;");
    return PermissionCollection(this->vm, this->vm->CallObjectMethod(this->inst.get(), newPermissionCollectionMethod));
}

String Permission::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
