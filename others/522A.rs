// Created: Aug  3 2026, 18:52:57
// Formatted with rustfmt.

use std::collections::HashMap;

fn dfs(s: &str, adj: &HashMap<String, Vec<String>>) -> i32 {
    adj.get(s)
        .map(|next| next.iter().map(|w| 1 + dfs(w, adj)).max().unwrap_or(0))
        .unwrap_or(0)
}

fn main() {
    let n: usize = read();
    let mut adj: HashMap<String, Vec<String>> = HashMap::new();
    for _ in 0..n {
        let mut a: String = read();
        let _ = read::<String>();
        let mut b: String = read();

        a.make_ascii_lowercase();
        b.make_ascii_lowercase();
        adj.entry(b.clone()).or_default().push(a.clone());
    }

    let ans = dfs("polycarp", &adj) + 1;
    println!("{ans}");
}

thread_local! {
    pub static INPUT: std::cell::RefCell<std::str::SplitAsciiWhitespace<'static>> = std::cell::RefCell::<std::str::SplitAsciiWhitespace<'static>>::new({
        let mut input = String::new();
        std::io::Read::read_to_string(&mut std::io::stdin(), &mut input).unwrap();
        Box::leak(input.into_boxed_str()).split_ascii_whitespace()
    });
}

pub fn read<T: std::str::FromStr>() -> T
where
    T::Err: std::fmt::Debug,
{
    INPUT.with(|input| input.borrow_mut().next().unwrap().parse().unwrap())
}
