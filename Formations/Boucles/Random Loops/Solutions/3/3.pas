program MultiplicationQuiz;
uses wincrt;

var
  score, i, a, b, rep, sugg: integer;

begin
  score := 0;
  randomize;

  for i := 1 to 10 do
  begin
    a := random(10) + 1;
    b := random(10) + 1;
    rep := a * b;

    write(a, ' x ', b, ' = ');
    readln(sugg);

    if rep = sugg then
      score := score + 1
    else
      score := score - 1;
  end;

  writeln('Your Score = ', score);
end.