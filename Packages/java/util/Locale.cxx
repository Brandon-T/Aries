//
//  Locale.cxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Locale.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "Collection.hxx"
#include "List.hxx"
#include "Set.hxx"
#include "Character.hxx"

using java::util::Locale;
using java::lang::Object;
using java::lang::String;
using java::util::Collection;
using java::util::List;
using java::util::Set;
using java::lang::Character;


Locale::Locale(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Locale;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Locale::Locale(JVM* vm, String language, String country, String variant) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Locale;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, language.ref().get(), country.ref().get(), variant.ref().get()));
    }
}

Locale::Locale(JVM* vm, String language, String country) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Locale;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, language.ref().get(), country.ref().get()));
    }
}

Locale::Locale(JVM* vm, String language) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Locale;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, language.ref().get()));
    }
}

Locale Locale::forLanguageTag(JVM* vm, String languageTag)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale;"));
    static jmethodID forLanguageTagMethod = vm->GetStaticMethodID(cls.get(), "forLanguageTag", "(Ljava/lang/String;)Ljava/util/Locale;");
    return Locale(vm, vm->CallStaticObjectMethod(cls.get(), forLanguageTagMethod, languageTag.ref().get()));
}

Array<Locale> Locale::getAvailableLocales(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale;"));
    static jmethodID getAvailableLocalesMethod = vm->GetStaticMethodID(cls.get(), "getAvailableLocales", "()[Ljava/util/Locale;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), getAvailableLocalesMethod));
    return Array<Locale>(vm, arr);
}

String Locale::getCountry()
{
    static jmethodID getCountryMethod = this->vm->GetMethodID(this->cls.get(), "getCountry", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getCountryMethod));
}

Locale Locale::getDefault(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale;"));
    static jmethodID getDefaultMethod = vm->GetStaticMethodID(cls.get(), "getDefault", "()Ljava/util/Locale;");
    return Locale(vm, vm->CallStaticObjectMethod(cls.get(), getDefaultMethod));
}

Locale Locale::getDefault(JVM* vm, Category category)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale;"));
    static jmethodID getDefaultMethod = vm->GetStaticMethodID(cls.get(), "getDefault", "(Ljava/util/Locale$Category;)Ljava/util/Locale;");
    return Locale(vm, vm->CallStaticObjectMethod(cls.get(), getDefaultMethod, category.ref().get()));
}

String Locale::getDisplayCountry()
{
    static jmethodID getDisplayCountryMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayCountry", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayCountryMethod));
}

String Locale::getDisplayCountry(Locale inLocale)
{
    static jmethodID getDisplayCountryMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayCountry", "(Ljava/util/Locale;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayCountryMethod, inLocale.ref().get()));
}

String Locale::getDisplayLanguage()
{
    static jmethodID getDisplayLanguageMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayLanguage", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayLanguageMethod));
}

String Locale::getDisplayLanguage(Locale inLocale)
{
    static jmethodID getDisplayLanguageMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayLanguage", "(Ljava/util/Locale;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayLanguageMethod, inLocale.ref().get()));
}

String Locale::getDisplayName()
{
    static jmethodID getDisplayNameMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayNameMethod));
}

String Locale::getDisplayName(Locale inLocale)
{
    static jmethodID getDisplayNameMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayName", "(Ljava/util/Locale;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayNameMethod, inLocale.ref().get()));
}

String Locale::getDisplayScript()
{
    static jmethodID getDisplayScriptMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayScript", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayScriptMethod));
}

String Locale::getDisplayScript(Locale inLocale)
{
    static jmethodID getDisplayScriptMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayScript", "(Ljava/util/Locale;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayScriptMethod, inLocale.ref().get()));
}

String Locale::getDisplayVariant()
{
    static jmethodID getDisplayVariantMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayVariant", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayVariantMethod));
}

String Locale::getDisplayVariant(Locale inLocale)
{
    static jmethodID getDisplayVariantMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayVariant", "(Ljava/util/Locale;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayVariantMethod, inLocale.ref().get()));
}

String Locale::getExtension(char key)
{
    static jmethodID getExtensionMethod = this->vm->GetMethodID(this->cls.get(), "getExtension", "(C)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getExtensionMethod, key));
}

Set<Character> Locale::getExtensionKeys()
{
    static jmethodID getExtensionKeysMethod = this->vm->GetMethodID(this->cls.get(), "getExtensionKeys", "()Ljava/util/Set;");
    return Set<Character>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getExtensionKeysMethod));
}

String Locale::getISO3Country()
{
    static jmethodID getISO3CountryMethod = this->vm->GetMethodID(this->cls.get(), "getISO3Country", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getISO3CountryMethod));
}

String Locale::getISO3Language()
{
    static jmethodID getISO3LanguageMethod = this->vm->GetMethodID(this->cls.get(), "getISO3Language", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getISO3LanguageMethod));
}

Array<String> Locale::getISOCountries(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale;"));
    static jmethodID getISOCountriesMethod = vm->GetStaticMethodID(cls.get(), "getISOCountries", "()[Ljava/lang/String;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), getISOCountriesMethod));
    return Array<String>(vm, arr);
}

Array<String> Locale::getISOLanguages(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale;"));
    static jmethodID getISOLanguagesMethod = vm->GetStaticMethodID(cls.get(), "getISOLanguages", "()[Ljava/lang/String;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), getISOLanguagesMethod));
    return Array<String>(vm, arr);
}

String Locale::getLanguage()
{
    static jmethodID getLanguageMethod = this->vm->GetMethodID(this->cls.get(), "getLanguage", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getLanguageMethod));
}

String Locale::getScript()
{
    static jmethodID getScriptMethod = this->vm->GetMethodID(this->cls.get(), "getScript", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getScriptMethod));
}

Set<String> Locale::getUnicodeLocaleAttributes()
{
    static jmethodID getUnicodeLocaleAttributesMethod = this->vm->GetMethodID(this->cls.get(), "getUnicodeLocaleAttributes", "()Ljava/util/Set;");
    return Set<String>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getUnicodeLocaleAttributesMethod));
}

Set<String> Locale::getUnicodeLocaleKeys()
{
    static jmethodID getUnicodeLocaleKeysMethod = this->vm->GetMethodID(this->cls.get(), "getUnicodeLocaleKeys", "()Ljava/util/Set;");
    return Set<String>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getUnicodeLocaleKeysMethod));
}

String Locale::getUnicodeLocaleType(String key)
{
    static jmethodID getUnicodeLocaleTypeMethod = this->vm->GetMethodID(this->cls.get(), "getUnicodeLocaleType", "(Ljava/lang/String;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getUnicodeLocaleTypeMethod, key.ref().get()));
}

String Locale::getVariant()
{
    static jmethodID getVariantMethod = this->vm->GetMethodID(this->cls.get(), "getVariant", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getVariantMethod));
}

bool Locale::hasExtensions()
{
    static jmethodID hasExtensionsMethod = this->vm->GetMethodID(this->cls.get(), "hasExtensions", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasExtensionsMethod);
}

void Locale::setDefault(JVM* vm, Locale newLocale)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale;"));
    static jmethodID setDefaultMethod = vm->GetStaticMethodID(cls.get(), "setDefault", "(Ljava/util/Locale;)V");
    vm->CallStaticVoidMethod(cls.get(), setDefaultMethod, newLocale.ref().get());
}

void Locale::setDefault(JVM* vm, Category category, Locale newLocale)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale;"));
    static jmethodID setDefaultMethod = vm->GetStaticMethodID(cls.get(), "setDefault", "(Ljava/util/Locale$Category;Ljava/util/Locale;)V");
    vm->CallStaticVoidMethod(cls.get(), setDefaultMethod, category.ref().get(), newLocale.ref().get());
}

Locale Locale::stripExtensions()
{
    static jmethodID stripExtensionsMethod = this->vm->GetMethodID(this->cls.get(), "stripExtensions", "()Ljava/util/Locale;");
    return Locale(this->vm, this->vm->CallObjectMethod(this->inst.get(), stripExtensionsMethod));
}

String Locale::toLanguageTag()
{
    static jmethodID toLanguageTagMethod = this->vm->GetMethodID(this->cls.get(), "toLanguageTag", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toLanguageTagMethod));
}

String Locale::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}




using java::lang::Enum;
using java::lang::String;


Locale::Category::Category(JVM* vm, jobject instance) : Enum(vm, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Locale$Category;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Locale::Category Locale::Category::valueOf(JVM* vm, String value)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale$Category;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(Ljava/lang/String;)Ljava/util/Locale$Category;");
    return Locale::Category(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, value.ref().get()));
}

Array<Locale::Category> Locale::Category::values(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/Locale$Category;"));
    static jmethodID valuesMethod = vm->GetStaticMethodID(cls.get(), "values", "()[Ljava/util/Locale$Category;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), valuesMethod));
    return Array<Locale::Category>(vm, arr);
}
