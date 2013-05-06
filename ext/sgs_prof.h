
#ifndef SGS_PROF_H_INCLUDED
#define SGS_PROF_H_INCLUDED

#include <sgscript.h>
#include <sgs_util.h>

typedef
struct _sgs_Prof
{
	SGS_CTX;
	sgs_HookFunc hfn;
	void* hctx;

	int mode;
	/* mode 1 */
	sgs_MemBuf keytmp;
	sgs_MemBuf timetmp;
	sgs_HashTable timings;
	/* mode 2 */
	int prev;
	double* ictrs;
	uint32_t* iexcs;
	uint32_t instr;
	double starttime;
}
sgs_Prof;

#define SGS_PROF sgs_Prof* P

#define SGS_PROF_FUNCTIME 1
#define SGS_PROF_OPTIME   2

SGSBOOL sgs_ProfInit( SGS_CTX, SGS_PROF, int mode );
SGSBOOL sgs_ProfClose( SGS_PROF );
SGSBOOL sgs_ProfDump( SGS_PROF );


#endif
