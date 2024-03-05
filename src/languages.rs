// #pragma once
// #include <string>
// #include <unordered_map>
// #include <vector>
// namespace numifier
// {
const ENGLISH_LOOKUP: &'static [(&str,i32)] = &[
    ( "one", 1 ),         
    ( "two", 2 ),
    ( "three", 3 ),
    ( "four", 4 ),
    ( "five", 5 ),
    ( "six", 6 ),
    ( "seven", 7 ),
    ( "eight", 8 ),
    ( "nine", 9 ),
    ( "ten", 10 ),
    ( "eleven", 11 ),
    ( "twelve", 12 ),
    ( "thirteen", 13 ),
    ( "fourteen", 14 ),
    ( "fifhteen", 15 ),
    ( "sixteen", 16 ),
    ( "seventeen", 17 ),
    ( "eighteen", 18 ),
    ( "nineteen", 19 ),
    ( "twenty", 20 ),
    ( "thirty", 30 ),
    ( "fourty", 40 ),
    ( "fifty", 50 ),
    ( "sixty", 60 ),
    ( "seventy", 70 ),
    ( "eighty", 80 ),
    ( "ninety", 90 ),
    ( "hundred", 100 ),
    ( "thousand", 1000 ),
    ( "million", 1000000 )    
    
    ];

pub enum Language{
    English,
    Hungarian,
    RomanNumerals,
}

pub fn possibleRoots<'a>(segment: &'a str, language:&'a  Language) ->  Vec<&'a (&'a str,i32)>  {
    match language {
        Language::English => possibleEnglishRoots(segment),
        Language::Hungarian => todo!(),
        Language::RomanNumerals => todo!(),
    }
}
fn possibleEnglishRoots(word: &str) -> Vec<&(&str,i32)> {
    
    ENGLISH_LOOKUP.iter().filter(|&x| x.0.starts_with(word) ).collect()
    
}
// struct LanguageData
// {
//     std::unordered_map<std::string, int> dictionary;
//     std::vector<std::string> separators;
// };

// static std::unordered_map<Language, LanguageData> languages = {

//     {
//         numifier::Language::ENGLISH,
//         {

//             {
//                 { "one", 1 },         { "two", 2 },           { "three", 3 },     { "four", 4 },
//                 { "five", 5 },        { "six", 6 },           { "seven", 7 },     { "eight", 8 },
//                 { "nine", 9 },        { "ten", 10 },          { "eleven", 11 },   { "twelve", 12 },
//                 { "thirteen", 13 },   { "fourteen", 14 },     { "fifhteen", 15 }, { "sixteen", 16 },
//                 { "seventeen", 17 },  { "eighteen", 18 },     { "nineteen", 19 }, { "twenty", 20 },
//                 { "thirty", 30 },     { "fourty", 40 },       { "fifty", 50 },    { "sixty", 60 },
//                 { "seventy", 70 },    { "eighty", 80 },       { "ninety", 90 },   { "hundred", 100 },
//                 { "thousand", 1000 }, { "million", 1000000 },
//             },
//             { "\\s+and\\s+", "\\s+", "-" } },
//     },
//     { numifier::Language::ROMAN_NUMERALS,
//       {

//           {
//               { "I", 1 },
//               { "V", 5 },
//               { "X", 10 },
//               { "L", 50 },
//               { "C", 100 },
//               { "D", 500 },
//               { "M", 1000 },
//           },
//           {} } },

//     { numifier::Language::HUNGARIAN,
//       {

//           {

//               { "egy", 1 },        { "kettő", 2 },  { "két", 2 },     { "három", 3 },        { "négy", 4 },
//               { "öt", 5 },         { "hat", 6 },    { "hét", 7 },     { "nyolc", 8 },        { "kilenc", 9 },
//               { "tíz", 10 },       { "tizen", 10 }, { "husz", 20 },   { "huszon", 20 },      { "harminc", 30 },
//               { "negyven", 40 },   { "ötven", 50 }, { "hatvan", 60 }, { "hetven", 70 },      { "nyolcvan", 80 },
//               { "kilencven", 90 }, { "száz", 100 }, { "ezer", 1000 }, { "millió", 1000000 },

//           },
//           {"\\s+", "-"} } },
// };

// }  // namespace numifier
