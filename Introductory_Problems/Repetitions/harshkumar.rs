use std::io::stdin;
fn main(){
    let mut inp = String::new();
    stdin().read_line(&mut inp).expect("Error in input");
    let mut res = 0;
    let mut temp = 1;
    let mut prev_char = inp.chars().nth(0).expect("error");
    for (idx,char) in inp.chars().enumerate(){
        if idx==0{
            continue;
        }
        if char==prev_char{
            temp+=1;
        }
        else{
            temp = 1
        }
        res=res.max(temp);
        prev_char=char;
    }
    println!("{}", res);
}