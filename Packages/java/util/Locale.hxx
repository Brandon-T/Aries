//
//  Locale.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Locale_hxx
#define Locale_hxx

#include "Array.hxx"
#include "Object.hxx"
#include "Enum.hxx"


namespace java::util
{
    using java::lang::Object;
    using java::lang::String;
    using java::util::Collection;
    using java::util::List;
    using java::util::Set;
    using java::lang::Enum;
    using java::lang::Character;
    
    
    class Locale : public Object
    {
    public:
        class Category : public Enum
        {
        public:
            Category(JVM* vm, jobject instance);
            
            static Category valueOf(JVM* vm, String value);
            static Array<Category> values(JVM* vm);
        };
        
        Locale(JVM* vm, jobject instance);
        Locale(JVM* vm, String language, String country, String variant);
        Locale(JVM* vm, String language, String country);
        Locale(JVM* vm, String language);
        static Locale forLanguageTag(JVM* vm, String languageTag);
        static Array<Locale> getAvailableLocales(JVM* vm);
        String getCountry();
        static Locale getDefault(JVM* vm);
        static Locale getDefault(JVM* vm, Category category);
        String getDisplayCountry();
        String getDisplayCountry(Locale inLocale);
        String getDisplayLanguage();
        String getDisplayLanguage(Locale inLocale);
        String getDisplayName();
        String getDisplayName(Locale inLocale);
        String getDisplayScript();
        String getDisplayScript(Locale inLocale);
        String getDisplayVariant();
        String getDisplayVariant(Locale inLocale);
        String getExtension(char key);
        Set<Character> getExtensionKeys();
        String getISO3Country();
        String getISO3Language();
        static Array<String> getISOCountries(JVM* vm);
        static Array<String> getISOLanguages(JVM* vm);
        String getLanguage();
        String getScript();
        Set<String> getUnicodeLocaleAttributes();
        Set<String> getUnicodeLocaleKeys();
        String getUnicodeLocaleType(String key);
        String getVariant();
        bool hasExtensions();
        static void setDefault(JVM* vm, Locale newLocale);
        static void setDefault(JVM* vm, Category category, Locale newLocale);
        Locale stripExtensions();
        String toLanguageTag();
        String toString();
    };
}

#endif /* Locale_hxx */
