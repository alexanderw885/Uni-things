fn main() {
    println!("Hello, world! {}", 123);

    let mut v = Vec::new();
    v.push(5);
    v.push(4);
    println!("{:?}",v); // Note the different printing syntax here
    println!("{:?}", v.get(1)); // it's also used for pulling items off vectors

    println!("---------------------------");
    println!("OPTIONS");
    let v = vec![10, 20, 30]; // initialization macro
    let idx = 0;

    match v.get(idx) {
        Some(value) => println!("Value is {}", value),
        None => println!("No value..."),
    }

    let another_idx = 10;
    match v.get(another_idx) {
        Some(value) => println!("Value is {}", value),
        None => println!("No value..."),
    }


}
