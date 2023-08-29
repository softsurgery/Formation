program PliagePapier;
uses wincrt;

var
  epaisseur: real;
  hauteurBurj, pliages: integer;
begin
  epaisseur := 0.1;
  hauteurBurj := 828;
  pliages := 0;

  while epaisseur < hauteurBurj * 1000 do
  begin
    epaisseur := epaisseur * 2;
    pliages := pliages + 1;
  end;

  writeln('Épaisseur initiale du papier : ', epaisseur:0:2, ' mm');
  writeln('Hauteur du Burj Khalifa : ', hauteurBurj, ' m');
  writeln('Nombre minimal de pliages nécessaires : ', pliages);
end.
