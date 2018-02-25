//
//  FileStoreAttributeView.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FileStoreAttributeView.hxx"
#include "Object.hxx"

using java::nio::file::attribute::FileStoreAttributeView;
using java::lang::Object;


FileStoreAttributeView::FileStoreAttributeView(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/attribute/FileStoreAttributeView;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
