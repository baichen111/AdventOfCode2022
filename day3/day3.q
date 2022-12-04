i:read0 `:input.txt;

f1:{
    albet:.Q.a,.Q.A;
    a:first half:(`int$count[x]%2) cut x;
    b:last half;
    l:first a where a in b;
    1+where l=albet
  }

show sum f1'[i];   / part1:7990

i2:3 cut i;
f2:{
    albet:.Q.a,.Q.A;
    1+where albet=x[0]first where (x[0] in x[1])&x[0] in x[2]
 }
show sum f2'[i2];   / part2: 2602