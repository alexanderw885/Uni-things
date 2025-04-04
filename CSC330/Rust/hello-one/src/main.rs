use std::env; // Lets us read stdin
use rand::Rng;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut name = "Phillis";

    if args.len() > 1 { // no parenthesis here
        name = &args[1] // note you don't need a semicolon here
    }

    let lucky_number = rand::rng().random_range(1..=100);

    println!("{name}, lucky: {lucky_number}");
}
