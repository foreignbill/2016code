var ax,bx,ww,l,r,ll,rr,aa,b,t,i,j,k,n,m:longint;
    d:array[1..200000,0..20]of longint;
    a:array[1..200000]of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
function log2(x:longint):extended;
begin
  log2:=ln(x)/ln(2);
end;
begin
  repeat
    read(n);
    if n=0 then break;
    readln(m);
    fillchar(d,sizeof(d),0);
    fillchar(a,sizeof(a),0);
    for i:=1 to n do read(a[i]);
    d[1,0]:=1;
    for i:=2 to n do if a[i]<>a[i-1] then
      begin
        d[i,0]:=1;
      end
      else d[i,0]:=d[i-1,0]+1;
    for i:=n downto 1 do
      for j:=1 to trunc(log2(n)) do
        begin
          k:=i+1<<(j-1);
          if k>n then d[i,j]:=d[i,j-1] else d[i,j]:=max(d[i,j-1],d[k,j-1]);
        end;
    for i:=1 to m do
      begin
        readln(aa,b);
        ax:=aa;
        bx:=b;
        l:=1;
        r:=n;
        repeat
          m:=(l+r)>>1;
          if a[m]>=a[aa] then r:=m-1 else l:=m+1;
        until l>r;
        ll:=l; l:=1; r:=n;
        repeat
          m:=(l+r)>>1;
          if a[m]>a[aa] then r:=m-1 else l:=m+1;
        until l>r;
        rr:=r; ww:=0;
        if a[ax]<>a[bx] then begin
                               aa:=rr+1;
 			       b:=bx;
			       k:=trunc(log2(b-aa+1));
			       ww:=max(d[aa,k],d[b-1<<k+1,k]);
			     end;
        aa:=ll;
        if a[bx]=a[rr] then rr:=bx;
        b:=rr-(ax-aa);
        k:=trunc(log2(b-aa+1));
        ww:=max(ww,max(d[aa,k],d[b-1<<k+1,k]));
        writeln(ww);
      end;
    until false;
end.
