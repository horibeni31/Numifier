use std::f32::consts::E;

use languages::{possibleRoots, Language};

mod languages;
pub fn parseWord(word: &str, language: Language) -> Option<i32> {
    let segments = segmentageString(word, &language);
    if (segments.len() == 0) {
        return None;
    }
    Some(constructNumber(&segments, 0, segments.len(), &language))
}
fn segmentageString(word: &str, language: &Language) -> Vec<i32> {
    let mut ret: Vec<i32> = vec![];
    let mut buffer = String::new();
    for (i, c) in word.chars().enumerate() {
        let mut newBuffer = buffer.clone();
        newBuffer.push(c);
        if (i == word.len() - 1) {
            buffer = newBuffer.clone();
        }
        let oldPossibleRoots = possibleRoots(&buffer, &language);

        if (oldPossibleRoots.len() > 0
            && (possibleRoots(&newBuffer, &language).len() == 0 || i == word.len() - 1))
        {
            let res = oldPossibleRoots.iter().find(|&x| x.0 == buffer);
            match res {
                Some(_) => ret.push(oldPossibleRoots.iter().find(|&x| x.0 == buffer).unwrap().1),
                None => {
                    println!("{}", buffer);
                }
            }

            buffer = c.to_string();
        } else {
            buffer = newBuffer.clone();
        }
    }
    return ret;
}

fn constructNumber(vec: &Vec<i32>, start: usize, end: usize, lang: &Language) -> i32 {
    let mut max = start;
    for i in (start + 1)..end {
        if (vec[i] > vec[max]) {
            max = i;
        }
    }

    //     if (lang == Language::RomanNumerals)
    // {
    //             int left = start == max ? 0 : constructNumber(vec, start, max, lang);
    //     int right = end - 1 == max ? 0 : constructNumber(vec, max + 1, end, lang);
    //     return vec[max] - left + right;
    // }
    // else
    // {
    let left = if start == max {
        1
    } else {
        constructNumber(vec, start, max, lang)
    };
    let right = if end - 1 == max {
        0
    } else {
        constructNumber(vec, max + 1, end, lang)
    };
    return vec[max] * left + right;
    // }
}

#[cfg(test)]
mod tests {
    use self::languages::possibleRoots;

    use super::*;

    #[test]
    fn testTrivial() {
        let number = parseWord("one", Language::English);
        assert!(number.is_some());
        assert_eq!(number.unwrap(), 1);
        
    }
}
