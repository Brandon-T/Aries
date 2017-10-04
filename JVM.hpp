//
//  JVM.hpp
//  Aries
//
//  Created by Brandon on 2017-08-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JVM_HPP_INCLUDED
#define JVM_HPP_INCLUDED

#include <jni.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <dlfcn.h>
#endif // defined

#include <stdexcept>
#include <vector>
#include <string>



#pragma GCC visibility push(hidden)

class JVM
{
private:
    JNIEnv* env;
    JavaVM* vm;
#if defined(_WIN32) || defined(_WIN64)
    HMODULE module;
#else
    void* module;
#endif // defined
    
    bool Init(int argc, const char* argv[]);
    jint JNI_GetDefaultJavaVMInitArgs(void *args);
    jint JNI_CreateJavaVM(JavaVM **pvm, void **penv, void *args);
    jint JNI_GetCreatedJavaVMs(JavaVM **, jsize, jsize *);
    
    
public:
    JVM();
    JVM(int argc, const char* argv[]);
    ~JVM();
    
    inline bool loaded() { return this->module != nullptr; }
    
    jint GetVersion();
    jclass DefineClass(const char *name, jobject loader, const jbyte *buf, jsize len);
    jclass FindClass(const char *name);
    jmethodID FromReflectedMethod(jobject method);
    jfieldID FromReflectedField(jobject field);
    jobject ToReflectedMethod(jclass cls, jmethodID methodID, jboolean isStatic);
    jclass GetSuperclass(jclass sub);
    jboolean IsAssignableFrom(jclass sub, jclass sup);
    jobject ToReflectedField(jclass cls, jfieldID fieldID, jboolean isStatic);
    jint Throw(jthrowable obj);
    jint ThrowNew(jclass clazz, const char *msg);
    jthrowable ExceptionOccurred();
    void ExceptionDescribe();
    void ExceptionClear();
    void FatalError(const char *msg);
    jint PushLocalFrame(jint capacity);
    jobject PopLocalFrame(jobject result);
    jobject NewGlobalRef(jobject lobj);
    void DeleteGlobalRef(jobject gref);
    void DeleteLocalRef(jobject obj);
    jboolean IsSameObject(jobject obj1, jobject obj2);
    jobject NewLocalRef(jobject ref);
    jint EnsureLocalCapacity(jint capacity);
    jobject AllocObject(jclass clazz);
    jobject NewObject(jclass clazz, jmethodID methodID, ...);
    jobject NewObjectV(jclass clazz, jmethodID methodID, va_list args);
    jobject NewObjectA(jclass clazz, jmethodID methodID, const jvalue *args);
    jclass GetObjectClass(jobject obj);
    jboolean IsInstanceOf(jobject obj, jclass clazz);
    jmethodID GetMethodID(jclass clazz, const char *name, const char *sig);
    jobject CallObjectMethod(jobject obj, jmethodID methodID, ...);
    jobject CallObjectMethodV(jobject obj, jmethodID methodID, va_list args);
    jobject CallObjectMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jboolean CallBooleanMethod(jobject obj, jmethodID methodID, ...);
    jboolean CallBooleanMethodV(jobject obj, jmethodID methodID, va_list args);
    jboolean CallBooleanMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jbyte CallByteMethod(jobject obj, jmethodID methodID, ...);
    jbyte CallByteMethodV(jobject obj, jmethodID methodID, va_list args);
    jbyte CallByteMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jchar CallCharMethod(jobject obj, jmethodID methodID, ...);
    jchar CallCharMethodV(jobject obj, jmethodID methodID, va_list);
    jchar CallCharMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jshort CallShortMethod(jobject obj, jmethodID methodID, ...);
    jshort CallShortMethodV(jobject obj, jmethodID methodID, va_list args);
    jshort CallShortMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jint CallIntMethod(jobject obj, jmethodID methodID, ...);
    jint CallIntMethodV(jobject obj, jmethodID methodID, va_list args);
    jint CallIntMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jlong CallLongMethod(jobject obj, jmethodID methodID, ...);
    jlong CallLongMethodV(jobject obj, jmethodID methodID, va_list args);
    jlong CallLongMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jfloat CallFloatMethod(jobject obj, jmethodID methodID, ...);
    jfloat CallFloatMethodV(jobject obj, jmethodID methodID, va_list args);
    jfloat CallFloatMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jdouble CallDoubleMethod(jobject obj, jmethodID methodID, ...);
    jdouble CallDoubleMethodV(jobject obj, jmethodID methodID, va_list args);
    jdouble CallDoubleMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    void CallVoidMethod(jobject obj, jmethodID methodID, ...);
    void CallVoidMethodV(jobject obj, jmethodID methodID, va_list args);
    void CallVoidMethodA(jobject obj, jmethodID methodID, const jvalue *args);
    jobject CallNonvirtualObjectMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jobject CallNonvirtualObjectMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jobject CallNonvirtualObjectMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jboolean CallNonvirtualBooleanMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jboolean CallNonvirtualBooleanMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jboolean CallNonvirtualBooleanMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jbyte CallNonvirtualByteMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jbyte CallNonvirtualByteMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jbyte CallNonvirtualByteMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jchar CallNonvirtualCharMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jchar CallNonvirtualCharMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jchar CallNonvirtualCharMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jshort CallNonvirtualShortMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jshort CallNonvirtualShortMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jshort CallNonvirtualShortMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jint CallNonvirtualIntMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jint CallNonvirtualIntMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jint CallNonvirtualIntMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jlong CallNonvirtualLongMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jlong CallNonvirtualLongMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jlong CallNonvirtualLongMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jfloat CallNonvirtualFloatMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jfloat CallNonvirtualFloatMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jfloat CallNonvirtualFloatMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jdouble CallNonvirtualDoubleMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    jdouble CallNonvirtualDoubleMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    jdouble CallNonvirtualDoubleMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    void CallNonvirtualVoidMethod(jobject obj, jclass clazz, jmethodID methodID, ...);
    void CallNonvirtualVoidMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args);
    void CallNonvirtualVoidMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);
    jfieldID GetFieldID(jclass clazz, const char *name, const char *sig);
    jobject GetObjectField(jobject obj, jfieldID fieldID);
    jboolean GetBooleanField(jobject obj, jfieldID fieldID);
    jbyte GetByteField(jobject obj, jfieldID fieldID);
    jchar GetCharField(jobject obj, jfieldID fieldID);
    jshort GetShortField(jobject obj, jfieldID fieldID);
    jint GetIntField(jobject obj, jfieldID fieldID);
    jlong GetLongField(jobject obj, jfieldID fieldID);
    jfloat GetFloatField(jobject obj, jfieldID fieldID);
    jdouble GetDoubleField(jobject obj, jfieldID fieldID);
    void SetObjectField(jobject obj, jfieldID fieldID, jobject val);
    void SetBooleanField(jobject obj, jfieldID fieldID, jboolean val);
    void SetByteField(jobject obj, jfieldID fieldID, jbyte val);
    void SetCharField(jobject obj, jfieldID fieldID, jchar val);
    void SetShortField(jobject obj, jfieldID fieldID, jshort val);
    void SetIntField(jobject obj, jfieldID fieldID, jint val);
    void SetLongField(jobject obj, jfieldID fieldID, jlong val);
    void SetFloatField(jobject obj, jfieldID fieldID, jfloat val);
    void SetDoubleField(jobject obj, jfieldID fieldID, jdouble val);
    jmethodID GetStaticMethodID(jclass clazz, const char *name, const char *sig);
    jobject CallStaticObjectMethod(jclass clazz, jmethodID methodID, ...);
    jobject CallStaticObjectMethodV(jclass clazz, jmethodID methodID, va_list args);
    jobject CallStaticObjectMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    jboolean CallStaticBooleanMethod(jclass clazz, jmethodID methodID, ...);
    jboolean CallStaticBooleanMethodV(jclass clazz, jmethodID methodID, va_list args);
    jboolean CallStaticBooleanMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    jbyte CallStaticByteMethod(jclass clazz, jmethodID methodID, ...);
    jbyte CallStaticByteMethodV(jclass clazz, jmethodID methodID, va_list args);
    jbyte CallStaticByteMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    jchar CallStaticCharMethod(jclass clazz, jmethodID methodID, ...);
    jchar CallStaticCharMethodV(jclass clazz, jmethodID methodID, va_list args);
    jchar CallStaticCharMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    jshort CallStaticShortMethod(jclass clazz, jmethodID methodID, ...);
    jshort CallStaticShortMethodV(jclass clazz, jmethodID methodID, va_list args);
    jshort CallStaticShortMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    jint CallStaticIntMethod(jclass clazz, jmethodID methodID, ...);
    jint CallStaticIntMethodV(jclass clazz, jmethodID methodID, va_list args);
    jint CallStaticIntMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    jlong CallStaticLongMethod(jclass clazz, jmethodID methodID, ...);
    jlong CallStaticLongMethodV(jclass clazz, jmethodID methodID, va_list args);
    jlong CallStaticLongMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    jfloat CallStaticFloatMethod(jclass clazz, jmethodID methodID, ...);
    jfloat CallStaticFloatMethodV(jclass clazz, jmethodID methodID, va_list args);
    jfloat CallStaticFloatMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    jdouble CallStaticDoubleMethod(jclass clazz, jmethodID methodID, ...);
    jdouble CallStaticDoubleMethodV(jclass clazz, jmethodID methodID, va_list args);
    jdouble CallStaticDoubleMethodA(jclass clazz, jmethodID methodID, const jvalue *args);
    void CallStaticVoidMethod(jclass cls, jmethodID methodID, ...);
    void CallStaticVoidMethodV(jclass cls, jmethodID methodID, va_list args);
    void CallStaticVoidMethodA(jclass cls, jmethodID methodID, const jvalue *args);
    jfieldID GetStaticFieldID(jclass clazz, const char *name, const char *sig);
    jobject GetStaticObjectField(jclass clazz, jfieldID fieldID);
    jboolean GetStaticBooleanField(jclass clazz, jfieldID fieldID);
    jbyte GetStaticByteField(jclass clazz, jfieldID fieldID);
    jchar GetStaticCharField(jclass clazz, jfieldID fieldID);
    jshort GetStaticShortField(jclass clazz, jfieldID fieldID);
    jint GetStaticIntField(jclass clazz, jfieldID fieldID);
    jlong GetStaticLongField(jclass clazz, jfieldID fieldID);
    jfloat GetStaticFloatField(jclass clazz, jfieldID fieldID);
    jdouble GetStaticDoubleField(jclass clazz, jfieldID fieldID);
    void SetStaticObjectField(jclass clazz, jfieldID fieldID, jobject value);
    void SetStaticBooleanField(jclass clazz, jfieldID fieldID, jboolean value);
    void SetStaticByteField(jclass clazz, jfieldID fieldID, jbyte value);
    void SetStaticCharField(jclass clazz, jfieldID fieldID, jchar value);
    void SetStaticShortField(jclass clazz, jfieldID fieldID, jshort value);
    void SetStaticIntField(jclass clazz, jfieldID fieldID, jint value);
    void SetStaticLongField(jclass clazz, jfieldID fieldID, jlong value);
    void SetStaticFloatField(jclass clazz, jfieldID fieldID, jfloat value);
    void SetStaticDoubleField(jclass clazz, jfieldID fieldID, jdouble value);
    jstring NewString(const jchar *unicode, jsize len);
    jsize GetStringLength(jstring str);
    const jchar *GetStringChars(jstring str, jboolean *isCopy);
    void ReleaseStringChars(jstring str, const jchar *chars);
    jstring NewStringUTF(const char *utf);
    jsize GetStringUTFLength(jstring str);
    const char* GetStringUTFChars(jstring str, jboolean *isCopy);
    void ReleaseStringUTFChars(jstring str, const char* chars);
    jsize GetArrayLength(jarray array);
    jobjectArray NewObjectArray(jsize len, jclass clazz, jobject init);
    jobject GetObjectArrayElement(jobjectArray array, jsize index);
    void SetObjectArrayElement(jobjectArray array, jsize index, jobject val);
    jbooleanArray NewBooleanArray(jsize len);
    jbyteArray NewByteArray(jsize len);
    jcharArray NewCharArray(jsize len);
    jshortArray NewShortArray(jsize len);
    jintArray NewIntArray(jsize len);
    jlongArray NewLongArray(jsize len);
    jfloatArray NewFloatArray(jsize len);
    jdoubleArray NewDoubleArray(jsize len);
    jboolean* GetBooleanArrayElements(jbooleanArray array, jboolean *isCopy);
    jbyte* GetByteArrayElements(jbyteArray array, jboolean *isCopy);
    jchar* GetCharArrayElements(jcharArray array, jboolean *isCopy);
    jshort* GetShortArrayElements(jshortArray array, jboolean *isCopy);
    jint* GetIntArrayElements(jintArray array, jboolean *isCopy);
    jlong* GetLongArrayElements(jlongArray array, jboolean *isCopy);
    jfloat* GetFloatArrayElements(jfloatArray array, jboolean *isCopy);
    jdouble* GetDoubleArrayElements(jdoubleArray array, jboolean *isCopy);
    void ReleaseBooleanArrayElements(jbooleanArray array, jboolean *elems, jint mode);
    void ReleaseByteArrayElements(jbyteArray array, jbyte *elems, jint mode);
    void ReleaseCharArrayElements(jcharArray array, jchar *elems, jint mode);
    void ReleaseShortArrayElements(jshortArray array, jshort *elems, jint mode);
    void ReleaseIntArrayElements(jintArray array, jint *elems, jint mode);
    void ReleaseLongArrayElements(jlongArray array, jlong *elems, jint mode);
    void ReleaseFloatArrayElements(jfloatArray array, jfloat *elems, jint mode);
    void ReleaseDoubleArrayElements(jdoubleArray array, jdouble *elems, jint mode);
    void GetBooleanArrayRegion(jbooleanArray array, jsize start, jsize len, jboolean *buf);
    void GetByteArrayRegion(jbyteArray array, jsize start, jsize len, jbyte *buf);
    void GetCharArrayRegion(jcharArray array, jsize start, jsize len, jchar *buf);
    void GetShortArrayRegion(jshortArray array, jsize start, jsize len, jshort *buf);
    void GetIntArrayRegion(jintArray array, jsize start, jsize len, jint *buf);
    void GetLongArrayRegion(jlongArray array, jsize start, jsize len, jlong *buf);
    void GetFloatArrayRegion(jfloatArray array, jsize start, jsize len, jfloat *buf);
    void GetDoubleArrayRegion(jdoubleArray array, jsize start, jsize len, jdouble *buf);
    void SetBooleanArrayRegion(jbooleanArray array, jsize start, jsize len, const jboolean *buf);
    void SetByteArrayRegion(jbyteArray array, jsize start, jsize len, const jbyte *buf);
    void SetCharArrayRegion(jcharArray array, jsize start, jsize len, const jchar *buf);
    void SetShortArrayRegion(jshortArray array, jsize start, jsize len, const jshort *buf);
    void SetIntArrayRegion(jintArray array, jsize start, jsize len, const jint *buf);
    void SetLongArrayRegion(jlongArray array, jsize start, jsize len, const jlong *buf);
    void SetFloatArrayRegion(jfloatArray array, jsize start, jsize len, const jfloat *buf);
    void SetDoubleArrayRegion(jdoubleArray array, jsize start, jsize len, const jdouble *buf);
    jint RegisterNatives(jclass clazz, const JNINativeMethod *methods, jint nMethods);
    jint UnregisterNatives(jclass clazz);
    jint MonitorEnter(jobject obj);
    jint MonitorExit(jobject obj);
    jint GetJavaVM(JavaVM **vm);
    void GetStringRegion(jstring str, jsize start, jsize len, jchar *buf);
    void GetStringUTFRegion(jstring str, jsize start, jsize len, char *buf);
    void* GetPrimitiveArrayCritical(jarray array, jboolean *isCopy);
    void ReleasePrimitiveArrayCritical(jarray array, void *carray, jint mode);
    const jchar* GetStringCritical(jstring string, jboolean *isCopy);
    void ReleaseStringCritical(jstring string, const jchar *cstring);
    jweak NewWeakGlobalRef(jobject obj);
    void DeleteWeakGlobalRef(jweak ref);
    jboolean ExceptionCheck();
    jobject NewDirectByteBuffer(void* address, jlong capacity);
    void* GetDirectBufferAddress(jobject buf);
    jlong GetDirectBufferCapacity(jobject buf);
    jobjectRefType GetObjectRefType(jobject obj);
};

#pragma GCC visibility pop

#endif // JVM_HPP_INCLUDED
