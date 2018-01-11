var a, b: int;

a := 16;
b := 8;

if a > b then
	a := a - 8;
end if;

if a < b then
	a := b;
else
	a := a - 1;
	b := b + 1;
end if;

if a = b then
	a := a - 1;
	b := b + 1;
elsif a < b then
	a := 32;
else
	b := 0;
end if;
