//
//  Character.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Character.hxx"
#include "Object.hxx"
#include "CharSequence.hxx"
#include "Object.hxx"
#include "String.hxx"

using java::lang::Character;
using java::lang::CharSequence;
using java::lang::Object;
using java::lang::String;


Character::Character(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Character;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Character::Character(JVM* vm, char value) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Character;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(C)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, value));
    }
}

std::int32_t Character::charCount(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID charCountMethod = vm->GetStaticMethodID(cls.get(), "charCount", "(I)I");
    return vm->CallStaticIntMethod(cls.get(), charCountMethod, codePoint);
}

char Character::charValue()
{
    static jmethodID charValueMethod = this->vm->GetMethodID(this->cls.get(), "charValue", "()C");
    return this->vm->CallCharMethod(this->inst.get(), charValueMethod);
}

std::int32_t Character::codePointAt(JVM* vm, CharSequence seq, std::int32_t index)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID codePointAtMethod = vm->GetStaticMethodID(cls.get(), "codePointAt", "(Ljava/lang/CharSequence;I)I");
    return vm->CallStaticIntMethod(cls.get(), codePointAtMethod, seq.ref().get(), index);
}

std::int32_t Character::codePointAt(JVM* vm, Array<char>& a, std::int32_t index)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID codePointAtMethod = vm->GetStaticMethodID(cls.get(), "codePointAt", "([CI)I");
    return vm->CallStaticIntMethod(cls.get(), codePointAtMethod, a.ref().get(), index);
}

std::int32_t Character::codePointAt(JVM* vm, Array<char>& a, std::int32_t index, std::int32_t limit)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID codePointAtMethod = vm->GetStaticMethodID(cls.get(), "codePointAt", "([CII)I");
    return vm->CallStaticIntMethod(cls.get(), codePointAtMethod, a.ref().get(), index, limit);
}

std::int32_t Character::codePointBefore(JVM* vm, CharSequence seq, std::int32_t index)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID codePointBeforeMethod = vm->GetStaticMethodID(cls.get(), "codePointBefore", "(Ljava/lang/CharSequence;I)I");
    return vm->CallStaticIntMethod(cls.get(), codePointBeforeMethod, seq.ref().get(), index);
}

std::int32_t Character::codePointBefore(JVM* vm, Array<char>& a, std::int32_t index)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID codePointBeforeMethod = vm->GetStaticMethodID(cls.get(), "codePointBefore", "([CI)I");
    return vm->CallStaticIntMethod(cls.get(), codePointBeforeMethod, a.ref().get(), index);
}

std::int32_t Character::codePointBefore(JVM* vm, Array<char>& a, std::int32_t index, std::int32_t start)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID codePointBeforeMethod = vm->GetStaticMethodID(cls.get(), "codePointBefore", "([CII)I");
    return vm->CallStaticIntMethod(cls.get(), codePointBeforeMethod, a.ref().get(), index, start);
}

std::int32_t Character::codePointCount(JVM* vm, CharSequence seq, std::int32_t beginIndex, std::int32_t endIndex)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID codePointCountMethod = vm->GetStaticMethodID(cls.get(), "codePointCount", "(Ljava/lang/CharSequence;II)I");
    return vm->CallStaticIntMethod(cls.get(), codePointCountMethod, seq.ref().get(), beginIndex, endIndex);
}

std::int32_t Character::codePointCount(JVM* vm, Array<char>& a, std::int32_t offset, std::int32_t count)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID codePointCountMethod = vm->GetStaticMethodID(cls.get(), "codePointCount", "([CII)I");
    return vm->CallStaticIntMethod(cls.get(), codePointCountMethod, a.ref().get(), offset, count);
}

std::int32_t Character::compare(JVM* vm, char x, char y)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID compareMethod = vm->GetStaticMethodID(cls.get(), "compare", "(CC)I");
    return vm->CallStaticIntMethod(cls.get(), compareMethod, x, y);
}

std::int32_t Character::compareTo(Character anotherCharacter)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/lang/Character;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, anotherCharacter.ref().get());
}

std::int32_t Character::digit(JVM* vm, char ch, std::int32_t radix)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID digitMethod = vm->GetStaticMethodID(cls.get(), "digit", "(CI)I");
    return vm->CallStaticIntMethod(cls.get(), digitMethod, ch, radix);
}

std::int32_t Character::digit(JVM* vm, std::int32_t codePoint, std::int32_t radix)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID digitMethod = vm->GetStaticMethodID(cls.get(), "digit", "(II)I");
    return vm->CallStaticIntMethod(cls.get(), digitMethod, codePoint, radix);
}

bool Character::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

char Character::forDigit(JVM* vm, std::int32_t digit, std::int32_t radix)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID forDigitMethod = vm->GetStaticMethodID(cls.get(), "forDigit", "(II)C");
    return vm->CallStaticCharMethod(cls.get(), forDigitMethod, digit, radix);
}

std::uint8_t Character::getDirectionality(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID getDirectionalityMethod = vm->GetStaticMethodID(cls.get(), "getDirectionality", "(C)B");
    return vm->CallStaticByteMethod(cls.get(), getDirectionalityMethod, ch);
}

std::uint8_t Character::getDirectionality(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID getDirectionalityMethod = vm->GetStaticMethodID(cls.get(), "getDirectionality", "(I)B");
    return vm->CallStaticByteMethod(cls.get(), getDirectionalityMethod, codePoint);
}

String Character::getName(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID getNameMethod = vm->GetStaticMethodID(cls.get(), "getName", "(I)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), getNameMethod, codePoint));
}

std::int32_t Character::getNumericValue(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID getNumericValueMethod = vm->GetStaticMethodID(cls.get(), "getNumericValue", "(C)I");
    return vm->CallStaticIntMethod(cls.get(), getNumericValueMethod, ch);
}

std::int32_t Character::getNumericValue(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID getNumericValueMethod = vm->GetStaticMethodID(cls.get(), "getNumericValue", "(I)I");
    return vm->CallStaticIntMethod(cls.get(), getNumericValueMethod, codePoint);
}

std::int32_t Character::getType(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID getTypeMethod = vm->GetStaticMethodID(cls.get(), "getType", "(C)I");
    return vm->CallStaticIntMethod(cls.get(), getTypeMethod, ch);
}

std::int32_t Character::getType(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID getTypeMethod = vm->GetStaticMethodID(cls.get(), "getType", "(I)I");
    return vm->CallStaticIntMethod(cls.get(), getTypeMethod, codePoint);
}

std::int32_t Character::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

std::int32_t Character::hashCode(JVM* vm, char value)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID hashCodeMethod = vm->GetStaticMethodID(cls.get(), "hashCode", "(C)I");
    return vm->CallStaticIntMethod(cls.get(), hashCodeMethod, value);
}

char Character::highSurrogate(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID highSurrogateMethod = vm->GetStaticMethodID(cls.get(), "highSurrogate", "(I)C");
    return vm->CallStaticCharMethod(cls.get(), highSurrogateMethod, codePoint);
}

bool Character::isAlphabetic(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isAlphabeticMethod = vm->GetStaticMethodID(cls.get(), "isAlphabetic", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isAlphabeticMethod, codePoint);
}

bool Character::isBmpCodePoint(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isBmpCodePointMethod = vm->GetStaticMethodID(cls.get(), "isBmpCodePoint", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isBmpCodePointMethod, codePoint);
}

bool Character::isDefined(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isDefinedMethod = vm->GetStaticMethodID(cls.get(), "isDefined", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isDefinedMethod, ch);
}

bool Character::isDefined(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isDefinedMethod = vm->GetStaticMethodID(cls.get(), "isDefined", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isDefinedMethod, codePoint);
}

bool Character::isDigit(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isDigitMethod = vm->GetStaticMethodID(cls.get(), "isDigit", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isDigitMethod, ch);
}

bool Character::isDigit(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isDigitMethod = vm->GetStaticMethodID(cls.get(), "isDigit", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isDigitMethod, codePoint);
}

bool Character::isHighSurrogate(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isHighSurrogateMethod = vm->GetStaticMethodID(cls.get(), "isHighSurrogate", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isHighSurrogateMethod, ch);
}

bool Character::isISOControl(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isISOControlMethod = vm->GetStaticMethodID(cls.get(), "isISOControl", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isISOControlMethod, ch);
}

bool Character::isISOControl(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isISOControlMethod = vm->GetStaticMethodID(cls.get(), "isISOControl", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isISOControlMethod, codePoint);
}

bool Character::isIdentifierIgnorable(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isIdentifierIgnorableMethod = vm->GetStaticMethodID(cls.get(), "isIdentifierIgnorable", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isIdentifierIgnorableMethod, ch);
}

bool Character::isIdentifierIgnorable(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isIdentifierIgnorableMethod = vm->GetStaticMethodID(cls.get(), "isIdentifierIgnorable", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isIdentifierIgnorableMethod, codePoint);
}

bool Character::isIdeographic(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isIdeographicMethod = vm->GetStaticMethodID(cls.get(), "isIdeographic", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isIdeographicMethod, codePoint);
}

bool Character::isJavaIdentifierPart(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isJavaIdentifierPartMethod = vm->GetStaticMethodID(cls.get(), "isJavaIdentifierPart", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isJavaIdentifierPartMethod, ch);
}

bool Character::isJavaIdentifierPart(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isJavaIdentifierPartMethod = vm->GetStaticMethodID(cls.get(), "isJavaIdentifierPart", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isJavaIdentifierPartMethod, codePoint);
}

bool Character::isJavaIdentifierStart(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isJavaIdentifierStartMethod = vm->GetStaticMethodID(cls.get(), "isJavaIdentifierStart", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isJavaIdentifierStartMethod, ch);
}

bool Character::isJavaIdentifierStart(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isJavaIdentifierStartMethod = vm->GetStaticMethodID(cls.get(), "isJavaIdentifierStart", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isJavaIdentifierStartMethod, codePoint);
}

bool Character::isJavaLetter(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isJavaLetterMethod = vm->GetStaticMethodID(cls.get(), "isJavaLetter", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isJavaLetterMethod, ch);
}

bool Character::isJavaLetterOrDigit(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isJavaLetterOrDigitMethod = vm->GetStaticMethodID(cls.get(), "isJavaLetterOrDigit", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isJavaLetterOrDigitMethod, ch);
}

bool Character::isLetter(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isLetterMethod = vm->GetStaticMethodID(cls.get(), "isLetter", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isLetterMethod, ch);
}

bool Character::isLetter(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isLetterMethod = vm->GetStaticMethodID(cls.get(), "isLetter", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isLetterMethod, codePoint);
}

bool Character::isLetterOrDigit(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isLetterOrDigitMethod = vm->GetStaticMethodID(cls.get(), "isLetterOrDigit", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isLetterOrDigitMethod, ch);
}

bool Character::isLetterOrDigit(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isLetterOrDigitMethod = vm->GetStaticMethodID(cls.get(), "isLetterOrDigit", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isLetterOrDigitMethod, codePoint);
}

bool Character::isLowSurrogate(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isLowSurrogateMethod = vm->GetStaticMethodID(cls.get(), "isLowSurrogate", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isLowSurrogateMethod, ch);
}

bool Character::isLowerCase(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isLowerCaseMethod = vm->GetStaticMethodID(cls.get(), "isLowerCase", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isLowerCaseMethod, ch);
}

bool Character::isLowerCase(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isLowerCaseMethod = vm->GetStaticMethodID(cls.get(), "isLowerCase", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isLowerCaseMethod, codePoint);
}

bool Character::isMirrored(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isMirroredMethod = vm->GetStaticMethodID(cls.get(), "isMirrored", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isMirroredMethod, ch);
}

bool Character::isMirrored(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isMirroredMethod = vm->GetStaticMethodID(cls.get(), "isMirrored", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isMirroredMethod, codePoint);
}

bool Character::isSpace(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isSpaceMethod = vm->GetStaticMethodID(cls.get(), "isSpace", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isSpaceMethod, ch);
}

bool Character::isSpaceChar(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isSpaceCharMethod = vm->GetStaticMethodID(cls.get(), "isSpaceChar", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isSpaceCharMethod, ch);
}

bool Character::isSpaceChar(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isSpaceCharMethod = vm->GetStaticMethodID(cls.get(), "isSpaceChar", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isSpaceCharMethod, codePoint);
}

bool Character::isSupplementaryCodePoint(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isSupplementaryCodePointMethod = vm->GetStaticMethodID(cls.get(), "isSupplementaryCodePoint", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isSupplementaryCodePointMethod, codePoint);
}

bool Character::isSurrogate(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isSurrogateMethod = vm->GetStaticMethodID(cls.get(), "isSurrogate", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isSurrogateMethod, ch);
}

bool Character::isSurrogatePair(JVM* vm, char high, char low)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isSurrogatePairMethod = vm->GetStaticMethodID(cls.get(), "isSurrogatePair", "(CC)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isSurrogatePairMethod, high, low);
}

bool Character::isTitleCase(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isTitleCaseMethod = vm->GetStaticMethodID(cls.get(), "isTitleCase", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isTitleCaseMethod, ch);
}

bool Character::isTitleCase(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isTitleCaseMethod = vm->GetStaticMethodID(cls.get(), "isTitleCase", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isTitleCaseMethod, codePoint);
}

bool Character::isUnicodeIdentifierPart(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isUnicodeIdentifierPartMethod = vm->GetStaticMethodID(cls.get(), "isUnicodeIdentifierPart", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isUnicodeIdentifierPartMethod, ch);
}

bool Character::isUnicodeIdentifierPart(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isUnicodeIdentifierPartMethod = vm->GetStaticMethodID(cls.get(), "isUnicodeIdentifierPart", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isUnicodeIdentifierPartMethod, codePoint);
}

bool Character::isUnicodeIdentifierStart(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isUnicodeIdentifierStartMethod = vm->GetStaticMethodID(cls.get(), "isUnicodeIdentifierStart", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isUnicodeIdentifierStartMethod, ch);
}

bool Character::isUnicodeIdentifierStart(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isUnicodeIdentifierStartMethod = vm->GetStaticMethodID(cls.get(), "isUnicodeIdentifierStart", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isUnicodeIdentifierStartMethod, codePoint);
}

bool Character::isUpperCase(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isUpperCaseMethod = vm->GetStaticMethodID(cls.get(), "isUpperCase", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isUpperCaseMethod, ch);
}

bool Character::isUpperCase(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isUpperCaseMethod = vm->GetStaticMethodID(cls.get(), "isUpperCase", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isUpperCaseMethod, codePoint);
}

bool Character::isValidCodePoint(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isValidCodePointMethod = vm->GetStaticMethodID(cls.get(), "isValidCodePoint", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isValidCodePointMethod, codePoint);
}

bool Character::isWhitespace(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isWhitespaceMethod = vm->GetStaticMethodID(cls.get(), "isWhitespace", "(C)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isWhitespaceMethod, ch);
}

bool Character::isWhitespace(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID isWhitespaceMethod = vm->GetStaticMethodID(cls.get(), "isWhitespace", "(I)Z");
    return vm->CallStaticBooleanMethod(cls.get(), isWhitespaceMethod, codePoint);
}

char Character::lowSurrogate(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID lowSurrogateMethod = vm->GetStaticMethodID(cls.get(), "lowSurrogate", "(I)C");
    return vm->CallStaticCharMethod(cls.get(), lowSurrogateMethod, codePoint);
}

std::int32_t Character::offsetByCodePoints(JVM* vm, CharSequence seq, std::int32_t index, std::int32_t codePointOffset)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID offsetByCodePointsMethod = vm->GetStaticMethodID(cls.get(), "offsetByCodePoints", "(Ljava/lang/CharSequence;II)I");
    return vm->CallStaticIntMethod(cls.get(), offsetByCodePointsMethod, seq.ref().get(), index, codePointOffset);
}

std::int32_t Character::offsetByCodePoints(JVM* vm, Array<char>& a, std::int32_t start, std::int32_t count, std::int32_t index, std::int32_t codePointOffset)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID offsetByCodePointsMethod = vm->GetStaticMethodID(cls.get(), "offsetByCodePoints", "([CIIII)I");
    return vm->CallStaticIntMethod(cls.get(), offsetByCodePointsMethod, a.ref().get(), start, count, index, codePointOffset);
}

char Character::reverseBytes(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID reverseBytesMethod = vm->GetStaticMethodID(cls.get(), "reverseBytes", "(C)C");
    return vm->CallStaticCharMethod(cls.get(), reverseBytesMethod, ch);
}

std::int32_t Character::toChars(JVM* vm, std::int32_t codePoint, Array<char>& dst, std::int32_t dstIndex)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toCharsMethod = vm->GetStaticMethodID(cls.get(), "toChars", "(I[CI)I");
    return vm->CallStaticIntMethod(cls.get(), toCharsMethod, codePoint, dst.ref().get(), dstIndex);
}

Array<char> Character::toChars(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toCharsMethod = vm->GetStaticMethodID(cls.get(), "toChars", "(I)[C");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), toCharsMethod, codePoint));
    return Array<char>(vm, arr);
}

std::int32_t Character::toCodePoint(JVM* vm, char high, char low)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toCodePointMethod = vm->GetStaticMethodID(cls.get(), "toCodePoint", "(CC)I");
    return vm->CallStaticIntMethod(cls.get(), toCodePointMethod, high, low);
}

char Character::toLowerCase(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toLowerCaseMethod = vm->GetStaticMethodID(cls.get(), "toLowerCase", "(C)C");
    return vm->CallStaticCharMethod(cls.get(), toLowerCaseMethod, ch);
}

std::int32_t Character::toLowerCase(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toLowerCaseMethod = vm->GetStaticMethodID(cls.get(), "toLowerCase", "(I)I");
    return vm->CallStaticIntMethod(cls.get(), toLowerCaseMethod, codePoint);
}

String Character::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

String Character::toString(JVM* vm, char c)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toStringMethod = vm->GetStaticMethodID(cls.get(), "toString", "(C)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), toStringMethod, c));
}

char Character::toTitleCase(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toTitleCaseMethod = vm->GetStaticMethodID(cls.get(), "toTitleCase", "(C)C");
    return vm->CallStaticCharMethod(cls.get(), toTitleCaseMethod, ch);
}

std::int32_t Character::toTitleCase(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toTitleCaseMethod = vm->GetStaticMethodID(cls.get(), "toTitleCase", "(I)I");
    return vm->CallStaticIntMethod(cls.get(), toTitleCaseMethod, codePoint);
}

char Character::toUpperCase(JVM* vm, char ch)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toUpperCaseMethod = vm->GetStaticMethodID(cls.get(), "toUpperCase", "(C)C");
    return vm->CallStaticCharMethod(cls.get(), toUpperCaseMethod, ch);
}

std::int32_t Character::toUpperCase(JVM* vm, std::int32_t codePoint)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID toUpperCaseMethod = vm->GetStaticMethodID(cls.get(), "toUpperCase", "(I)I");
    return vm->CallStaticIntMethod(cls.get(), toUpperCaseMethod, codePoint);
}

Character Character::valueOf(JVM* vm, char c)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Character;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(C)Ljava/lang/Character;");
    return Character(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, c));
}
