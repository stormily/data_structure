#include <cstdlib>
#include <iostream>
#include "constant.h"
#include "sqlist.h"

using namespace std;

void MergeList_Sq(SqList la, SqList lb, SqList &lc) {
	ElemType *pa, *pb, *pc, *pa_last, *pb_last;
	pa = la.elem; 
	pb = lb.elem;
	lc.listsize = lc.length = la.length + lb.length;
	pc = lc.elem = new ElemType[lc.listsize];
	if (!lc.elem)
		exit(OVERFLOW);
	pa_last = la.elem + la.length - 1;
	pb_last = lb.elem + lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++;
	while (pb <= pb_last)
		*pc++ = *pb++;

}