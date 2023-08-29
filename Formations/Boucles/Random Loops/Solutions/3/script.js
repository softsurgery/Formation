let score = 0;

for (let i = 0; i < 10; i++) {
    let a = Math.floor(Math.random() * 10) + 1;
    let b = Math.floor(Math.random() * 10) + 1;
    let rep = a * b;
    let sugg = parseInt(prompt(`${a} x ${b} = ?`));
    if (rep === sugg) {
        score++;
    } else {
        score--;
    }
}
console.log(`Your Score = ${score}`);
