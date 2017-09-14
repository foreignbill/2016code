var 
  s,i,j,n,min:longint; 
  t:array[1..100]of integer;   a:real; 
begin 
readln(n);   
s:=0; 
for i:=1 to n do read(t[i]); 
repeat  
min:=32767; 
j:=0;  
for i:=1 to n do 
	if t[i]<>0 then begin j:=j+1; if t[i]<t[min] then min:=i; end; 
s:=s+t[min]*(j-1); 
t[min]:=0;  
write(output,min,' '); 
until j=1; 
a:=s/n;  
writeln(); 
writeln(a:0:2); 
end.
