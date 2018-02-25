//
//  UserPrincipalLookupService.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "UserPrincipalLookupService.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "GroupPrincipal.hxx"
#include "UserPrincipal.hxx"

using java::nio::file::attribute::UserPrincipalLookupService;
using java::lang::Object;
using java::lang::String;
using java::nio::file::attribute::GroupPrincipal;
using java::nio::file::attribute::UserPrincipal;


UserPrincipalLookupService::UserPrincipalLookupService(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/attribute/UserPrincipalLookupService;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

GroupPrincipal UserPrincipalLookupService::lookupPrincipalByGroupName(String group)
{
    static jmethodID lookupPrincipalByGroupNameMethod = this->vm->GetMethodID(this->cls.get(), "lookupPrincipalByGroupName", "(Ljava/lang/String;)Ljava/nio/file/attribute/GroupPrincipal;");
    return GroupPrincipal(this->vm, this->vm->CallObjectMethod(this->inst.get(), lookupPrincipalByGroupNameMethod, group.ref().get()));
}

UserPrincipal UserPrincipalLookupService::lookupPrincipalByName(String name)
{
    static jmethodID lookupPrincipalByNameMethod = this->vm->GetMethodID(this->cls.get(), "lookupPrincipalByName", "(Ljava/lang/String;)Ljava/nio/file/attribute/UserPrincipal;");
    return UserPrincipal(this->vm, this->vm->CallObjectMethod(this->inst.get(), lookupPrincipalByNameMethod, name.ref().get()));
}

UserPrincipalLookupService::UserPrincipalLookupService(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/attribute/UserPrincipalLookupService;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}
