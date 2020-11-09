typedef struct SymbTbl {
  char *column; 
  char *table;
  int type; 
	struct SymbTbl *next; 
} symbtbl;

extern symbtbl *st; 

symbtbl *putsymb(char *,char *,int);
symbtbl *getsymb(char *);
