//
//  ZipEntry.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ZipEntry.hpp"
#include "String.hpp"

using namespace java::util::zip;
using namespace java::lang;

ZipEntry::ZipEntry(JVM* jvm, jobject instance) : Object()
{
    if (instance)
    {
        this->vm = jvm;
        this->cls = this->vm->FindClass("Ljava/util/zip/ZipEntry;");
        this->inst = jvm->NewGlobalRef(instance);
    }
}

ZipEntry::ZipEntry(JVM* jvm, String name) : Object()
{
    this->vm = vm;
    this->cls = this->vm->FindClass("Ljava/util/zip/ZipEntry;");
    
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/String;)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, name.ref().get()));
}

ZipEntry::ZipEntry(JVM* vm, ZipEntry entry) : Object()
{
    this->vm = vm;
    this->cls = this->vm->FindClass("Ljava/util/zip/ZipEntry;");
    
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/util/zip/ZipEntry;)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, entry.ref().get()));
}

ZipEntry::~ZipEntry()
{
    
}

ZipEntry* ZipEntry::clone()
{
    jmethodID cloneMethod = this->vm->GetMethodID(this->cls, "clone", "()Ljava/util/zip/ZipEntry;");
    return new ZipEntry(this->vm, this->vm->CallObjectMethod(this->inst, cloneMethod));
}

String ZipEntry::getComment()
{
    jmethodID getCommentMethod = this->vm->GetMethodID(this->cls, "getComment", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getCommentMethod));
}

jlong ZipEntry::getCompressedSize()
{
    jmethodID getCompressedSizeMethod = this->vm->GetMethodID(this->cls, "getCompressedSize", "()J");
    return this->vm->CallLongMethod(this->inst, getCompressedSizeMethod);
}

jlong ZipEntry::getCrc()
{
    jmethodID getCrcMethod = this->vm->GetMethodID(this->cls, "getCrc", "()J");
    return this->vm->CallLongMethod(this->inst, getCrcMethod);
}

std::vector<jbyte> ZipEntry::getExtra()
{
    jmethodID getExtraMethod = this->vm->GetMethodID(this->cls, "getExtra", "()[B");
    jbyteArray bytes = reinterpret_cast<jbyteArray>(this->vm->CallObjectMethod(this->inst, getExtraMethod));
    
    std::vector<jbyte> result(this->vm->GetArrayLength(bytes));
    
    void* arr = this->vm->GetPrimitiveArrayCritical(bytes, nullptr);
    memcpy(&result[0], arr, result.size() * sizeof(jbyte));
    this->vm->ReleasePrimitiveArrayCritical(bytes, arr, 0);
    return result;
}

jint ZipEntry::getMethod()
{
    jmethodID getMethodMethod = this->vm->GetMethodID(this->cls, "getMethod", "()I");
    return this->vm->CallIntMethod(this->inst, getMethodMethod);
}

String ZipEntry::getName()
{
    jmethodID getNameMethod = this->vm->GetMethodID(this->cls, "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getNameMethod));
}

jlong ZipEntry::getSize()
{
    jmethodID getSizeMethod = this->vm->GetMethodID(this->cls, "getSize", "()J");
    return this->vm->CallLongMethod(this->inst, getSizeMethod);
}

jlong ZipEntry::getTime()
{
    jmethodID getTimeMethod = this->vm->GetMethodID(this->cls, "getTime", "()J");
    return this->vm->CallLongMethod(this->inst, getTimeMethod);
}

bool ZipEntry::isDirectory()
{
    jmethodID isDirectoryMethod = this->vm->GetMethodID(this->cls, "isDirectory", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isDirectoryMethod);
}
