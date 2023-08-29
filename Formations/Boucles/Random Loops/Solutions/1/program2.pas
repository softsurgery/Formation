program solution;
uses wincrt;
var
    s,i:Integer;
Begin
    s:=0;
    i:=1;
    while (i<=991) do
    begin
       s:=s+i;
       i:=i+2;
    end;
    i:=3;
    while (i<=99) do
    begin
       s:=s+i;
       i:=i+2;
    end;
    WriteLn('Resultat=',S);
end.
