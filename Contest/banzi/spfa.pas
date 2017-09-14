var n,x,y,z,ee,s,t,f,r,i,k,now,cnt:longint;
    next,e,w,head,dist,q:array[0..1000]of longint;
    v:array[0..1000]of boolean;
procedure link(x,y,z:longint);
begin
  inc(cnt);
  e[cnt]:=y;
  next[cnt]:=head[x];
  head[x]:=cnt;
  w[cnt]:=z;
end;
begin
  read(n,ee);
  for i:=1 to ee do
    begin
      read(x,y,z);
      link(x,y,z);
      link(y,x,z);
    end;
  read(s,t);
  fillchar(dist,sizeof(dist),63);
  fillchar(v,sizeof(v),0);
  f:=1;r:=1;
  q[1]:=s;
  v[s]:=true;
  dist[s]:=0;
  while f<=r do
  begin
    now:=q[f];
    k:=head[now];
    while k>0 do
      begin
        if dist[e[k]]>dist[now]+w[k] then
          begin
            dist[e[k]]:=dist[now]+w[k];
            if not v[e[k]] then
              begin
                inc(r);
                q[r]:=e[k];
                v[e[k]]:=true;
              end;
          end;
        k:=next[k];
      end;
    inc(f);
    v[now]:=false;
  end;
  writeln(dist[t]);
end.
