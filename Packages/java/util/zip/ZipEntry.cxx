//
//  ZipEntry.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ZipEntry.hxx"
#include "String.hxx"

using java::lang::String;
using java::util::zip::ZipEntry;

ZipEntry::ZipEntry(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/ZipEntry;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

ZipEntry::ZipEntry(JVM* jvm, String name) : Object()
{
    if (jvm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/ZipEntry;"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, name.ref().get()));
    }
}

ZipEntry::ZipEntry(JVM* jvm, ZipEntry entry) : Object()
{
    if (jvm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/ZipEntry;"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/util/zip/ZipEntry;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, entry.ref().get()));
    }
}

ZipEntry* ZipEntry::clone()
{
    jmethodID cloneMethod = this->vm->GetMethodID(this->cls.get(), "clone", "()Ljava/util/zip/ZipEntry;");
    return new ZipEntry(this->vm, this->vm->CallObjectMethod(this->inst.get(), cloneMethod));
}

String ZipEntry::getComment()
{
    jmethodID getCommentMethod = this->vm->GetMethodID(this->cls.get(), "getComment", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getCommentMethod));
}

jlong ZipEntry::getCompressedSize()
{
    jmethodID getCompressedSizeMethod = this->vm->GetMethodID(this->cls.get(), "getCompressedSize", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getCompressedSizeMethod);
}

jlong ZipEntry::getCrc()
{
    jmethodID getCrcMethod = this->vm->GetMethodID(this->cls.get(), "getCrc", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getCrcMethod);
}

Array<jbyte> ZipEntry::getExtra()
{
    jmethodID getExtraMethod = this->vm->GetMethodID(this->cls.get(), "getExtra", "()[B");
    jbyteArray bytes = reinterpret_cast<jbyteArray>(this->vm->CallObjectMethod(this->inst.get(), getExtraMethod));
    return Array<jbyte>(this->vm, bytes);
}

jint ZipEntry::getMethod()
{
    jmethodID getMethodMethod = this->vm->GetMethodID(this->cls.get(), "getMethod", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getMethodMethod);
}

String ZipEntry::getName()
{
    jmethodID getNameMethod = this->vm->GetMethodID(this->cls.get(), "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getNameMethod));
}

jlong ZipEntry::getSize()
{
    jmethodID getSizeMethod = this->vm->GetMethodID(this->cls.get(), "getSize", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getSizeMethod);
}

jlong ZipEntry::getTime()
{
    jmethodID getTimeMethod = this->vm->GetMethodID(this->cls.get(), "getTime", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getTimeMethod);
}

bool ZipEntry::isDirectory()
{
    jmethodID isDirectoryMethod = this->vm->GetMethodID(this->cls.get(), "isDirectory", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectoryMethod);
}
