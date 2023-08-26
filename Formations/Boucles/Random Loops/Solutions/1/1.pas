program solution;
uses wincrt;
var
    s,i:Integer;
Begin
    s:=0;
    for i:=1 to 1001 do s:=s+i;
    for i:=2 to 100 do s:=s+i;
    WriteLn('Resultat=',S);
end.
