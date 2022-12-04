i:read0 `:input.txt;

f:{
    albet:.Q.a,.Q.A;
    a:first half:(`int$count[x]%2) cut x;
    b:last half;
    l:first a where a in b;
    1+where l=albet
  }

show sum f'[i];   / part1:7990