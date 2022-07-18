
int main() {
	
	int i, j, *p, *q;
	
	p = &i;
//	*q = &j;
	p = &*&i;
//	i = (*&)j;
	i = *&*&j;
//	q = &p;
//	i = (*p)++ + *q;
//	if(p == i) i++;
	
	
	return 0;
}
