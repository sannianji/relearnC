#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf
{
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
}myFILE;

extern myFILE _iob[OPEN_MAX];

#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flag
{
	_READ 	= 01,
	_WRITE 	= 02,
	_UNBUF 	= 04,
	_EOF 	= 010,
	_ERR	=020
};

int _fillbuf(FILE *);
int _flushbuf(int,FILE *);

#define feof(p)  	(((p)->flag & _EOF)!=0)
#define ferror(p)	(((p)->flag & _ERR)!=0)
#define	getc(p)		((p)->fd)

#define	getc(p)	(--(p)->cnt>=0 ?*(p)->ptr++:fillbuf(p))
#define	putc(p)	(--(p)->cnt>=0 ?*(p)->ptr++=(x):_flushbuf((x),p))

#define getchar() getc(stdin)
#define putchar(x) putc((x),stdout)

