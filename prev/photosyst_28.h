#define	MAXCPU_28		2048
#define	MAXDSK_28		1024
#define	MAXNUMA_28		1024
#define	MAXLVM_28		2048
#define	MAXMDD_28		256
#define	MAXINTF_28		128
#define	MAXCONTAINER_28	128
#define	MAXNFSMOUNT_28	64
#define	MAXIBPORT_28	32
#define	MAXGPU_28		32
#define	MAXGPUBUS_28	12
#define	MAXGPUTYPE_28	12
#define	MAXLLC_28		256

#define	MAXDKNAM_28	32
#define	MAXIBNAME_28	12

/************************************************************************/
struct	memstat_28 {
	count_t	physmem;	// number of physical pages
	count_t	freemem;	// number of free     pages
	count_t	buffermem;	// number of buffer   pages
	count_t	slabmem;	// number of slab     pages
	count_t	cachemem;	// number of cache    pages
	count_t	cachedrt;	// number of cache    pages (dirty)

	count_t	totswap;	// number of pages in swap
	count_t	freeswap;	// number of free swap pages

	count_t	pgscans;	// number of page scans
	count_t	pgsteal;	// number of page steals
	count_t	allocstall;	// try to free pages forced
	count_t	swouts;		// number of pages swapped out
	count_t	swins;		// number of pages swapped in
	count_t	tcpsock;	// number of pages allocated by TCP sockets
	count_t	udpsock;	// number of pages allocated by UDP sockets

	count_t	commitlim;	// commit limit in pages
	count_t	committed;	// number of reserved pages

	count_t	shmem;		// tot shmem incl. tmpfs (pages)
	count_t	shmrss;		// resident shared memory (pages)
	count_t	shmswp;		// swapped shared memory (pages)

	count_t	slabreclaim;	// reclaimable slab (pages)

	count_t	tothugepage;	// total huge pages (huge pages)
	count_t	freehugepage;	// free  huge pages (huge pages)
	count_t	hugepagesz;	// huge page size (bytes)

	count_t	vmwballoon;	// vmware claimed balloon pages
	count_t	zfsarcsize;	// zfsonlinux ARC size (pages)
	count_t swapcached;	// swap cache (pages)
	count_t	ksmsharing;	// saved i.e. deduped memory (pages)
	count_t	ksmshared;	// current size shared pages (pages)
	count_t	zswstored;	// zswap stored pages (pages)
	count_t	zswtotpool;	// total pool size (pages)
	count_t	oomkills;	// number of oom killings
	count_t	compactstall;	// counter for process stalls
	count_t	pgmigrate;	// counter for migrated successfully (pages)
	count_t	numamigrate;	// counter for numa migrated (pages)
	count_t	pgouts;		// total number of pages written to block device
	count_t	pgins;		// total number of pages read from block device
	count_t	pagetables;	// page tables of processes (pages)
	count_t	cfuture[4];	// reserved for future use
};

/************************************************************************/

struct	mempernuma_28 {
	int	numanr;
	float	frag;		// fragmentation level for this numa
	count_t	totmem;		// number of physical pages for this numa
	count_t	freemem;	// number of free     pages for this numa
	count_t	filepage;	// number of file     pages for this numa
	count_t	dirtymem;	// number of cache    pages (dirty) for this numa
	count_t	slabmem;	// number of slab     pages for this numa
	count_t	slabreclaim;	// reclaimable slab (pages) for this numa

	count_t	active;		// number of pages used more recently for this numa
	count_t	inactive;	// number of pages less recently used for this numa

	count_t	shmem;		// tot shmem incl. tmpfs (pages) for this numa
	count_t	tothp;		// total huge pages (huge pages) for this numa
};

struct	memnuma_28 {
	count_t           nrnuma;		/* the counts of numa		*/
	struct mempernuma_28 numa[MAXNUMA_28];
};

struct	cpupernuma_28 {
	int	numanr;
	count_t	nrcpu;		// number of cpu's
	count_t	stime;		// accumulate system  time in clock ticks for per numa
	count_t	utime;		// accumulate user    time in clock ticks for per numa
	count_t	ntime;		// accumulate nice    time in clock ticks for per numa
	count_t	itime;		// accumulate idle    time in clock ticks for per numa
	count_t	wtime;		// accumulate iowait  time in clock ticks for per numa
	count_t	Itime;		// accumulate irq     time in clock ticks for per numa
	count_t	Stime;		// accumulate softirq time in clock ticks for per numa
	count_t	steal;		// accumulate steal   time in clock ticks for per numa
	count_t	guest;		// accumulate guest   time in clock ticks for per numa
};

struct	cpunuma_28 {
	count_t           nrnuma;		/* the counts of numa		*/
	struct cpupernuma_28 numa[MAXNUMA_28];
};

/************************************************************************/

struct	netstat_28 {
	struct ipv4_stats	ipv4;
	struct icmpv4_stats	icmpv4;
	struct udpv4_stats	udpv4;

	struct ipv6_stats	ipv6;
	struct icmpv6_stats	icmpv6;
	struct udpv6_stats	udpv6;

	struct tcp_stats	tcp;
};

/************************************************************************/

struct freqcnt_28 {
        count_t maxfreq;/* frequency in MHz                    */
        count_t cnt;    /* number of clock ticks times state   */
        count_t ticks;  /* number of total clock ticks         */
                        /* if zero, cnt is actual freq         */
};

struct percpu_28 {
	int		cpunr;
	count_t		stime;	/* system  time in clock ticks		*/
	count_t		utime;	/* user    time in clock ticks		*/
	count_t		ntime;	/* nice    time in clock ticks		*/
	count_t		itime;	/* idle    time in clock ticks		*/
	count_t		wtime;	/* iowait  time in clock ticks		*/
	count_t		Itime;	/* irq     time in clock ticks		*/
	count_t		Stime;	/* softirq time in clock ticks		*/
	count_t		steal;	/* steal   time in clock ticks		*/
	count_t		guest;	/* guest   time in clock ticks		*/
        struct freqcnt_28	freqcnt;/* frequency scaling info  		*/
	count_t		instr;	/* CPU instructions 			*/
	count_t		cycle;	/* CPU cycles 				*/
	count_t		cfuture[6];	/* reserved for future use	*/
};

struct	cpustat_28 {
	count_t	nrcpu;	/* number of cpu's 			*/
	count_t	devint;	/* number of device interrupts 		*/
	count_t	csw;	/* number of context switches		*/
	count_t	nprocs;	/* number of processes started          */
	float	lavg1;	/* load average last    minute          */
	float	lavg5;	/* load average last  5 minutes         */
	float	lavg15;	/* load average last 15 minutes         */
	count_t	cfuture[4];	/* reserved for future use	*/

	struct percpu_28   all;
	struct percpu_28   cpu[MAXCPU_28];
};

/************************************************************************/

struct	perdsk_28 {
        char	name[MAXDKNAM_28];	/* empty string for last		*/
        count_t	nread;		/* number of read  transfers		*/
        count_t	nrsect;		/* number of sectors read		*/
        count_t	nwrite;		/* number of write transfers		*/
        count_t	nwsect;		/* number of sectors written		*/
        count_t	io_ms;		/* number of millisecs spent for I/O	*/
        count_t	avque;		/* average queue length			*/
        count_t	ndisc;		/* number of discards (-1 = unavailable)*/
        count_t	ndsect;		/* number of sectors discarded		*/
        count_t	inflight;	/* number of inflight I/O		*/
        count_t	cfuture[3];	/* reserved for future use		*/
};

struct dskstat_28 {
	int		ndsk;	/* number of physical disks	*/
	int		nmdd;	/* number of md volumes		*/
	int		nlvm;	/* number of logical volumes	*/
	struct perdsk_28	dsk[MAXDSK_28];
	struct perdsk_28	mdd[MAXMDD_28];
	struct perdsk_28	lvm[MAXLVM_28];
};

/************************************************************************/

struct	perintf_28 {
        char	name[16];	/* empty string for last        */

        count_t	rbyte;	/* number of read bytes                 */
        count_t	rpack;	/* number of read packets               */
	count_t rerrs;  /* receive errors                       */
	count_t rdrop;  /* receive drops                        */
	count_t rfifo;  /* receive fifo                         */
	count_t rframe; /* receive framing errors               */
	count_t rcompr; /* receive compressed                   */
	count_t rmultic;/* receive multicast                    */
	count_t	rfuture[4];	/* reserved for future use	*/

        count_t	sbyte;	/* number of written bytes              */
        count_t	spack;	/* number of written packets            */
	count_t serrs;  /* transmit errors                      */
	count_t sdrop;  /* transmit drops                       */
	count_t sfifo;  /* transmit fifo                        */
	count_t scollis;/* collisions                           */
	count_t scarrier;/* transmit carrier                    */
	count_t scompr; /* transmit compressed                  */
	count_t	sfuture[4];	/* reserved for future use	*/

	char 	type;	/* interface type ('e'/'w'/'v'/'?')  	*/
	long 	speed;	/* interface speed in megabits/second	*/
	long 	speedp;	/* previous interface speed 		*/
	char	duplex;	/* full duplex (boolean) 		*/
	count_t	cfuture[4];	/* reserved for future use	*/
};

struct intfstat_28 {
	int		nrintf;
	struct perintf_28	intf[MAXINTF_28];
};

/************************************************************************/

struct  pernfsmount_28 {
        char 	mountdev[128];		/* mountdevice 			*/
        count_t	age;			/* number of seconds mounted	*/
	
	count_t	bytesread;		/* via normal reads		*/
	count_t	byteswrite;		/* via normal writes		*/
	count_t	bytesdread;		/* via direct reads		*/
	count_t	bytesdwrite;		/* via direct writes		*/
	count_t	bytestotread;		/* via reads			*/
	count_t	bytestotwrite;		/* via writes			*/
	count_t	pagesmread;		/* via mmap  reads		*/
	count_t	pagesmwrite;		/* via mmap  writes		*/

	count_t	future[8];
};

struct nfsstat_28 {
	struct {
        	count_t	netcnt;
		count_t netudpcnt;
		count_t nettcpcnt;
		count_t nettcpcon;

		count_t rpccnt;
		count_t rpcbadfmt;
		count_t rpcbadaut;
		count_t rpcbadcln;

		count_t rpcread;
		count_t rpcwrite;

	   	count_t	rchits;		/* repcache hits	*/
	   	count_t	rcmiss;		/* repcache misses	*/
	   	count_t	rcnoca;		/* uncached requests	*/

	   	count_t	nrbytes;	/* read bytes		*/
	   	count_t	nwbytes;	/* written bytes	*/

		count_t	future[8];
	} server;

	struct {
		count_t	rpccnt;
		count_t rpcretrans;
		count_t rpcautrefresh;

		count_t rpcread;
		count_t rpcwrite;

		count_t	future[8];
	} client;

	struct {
        	int             	nrmounts;
       		struct pernfsmount	nfsmnt[MAXNFSMOUNT_28];
	} nfsmounts;
};

/************************************************************************/
struct	psi_28 {
	float	avg10;		// average pressure last 10 seconds
	float	avg60;		// average pressure last 60 seconds
	float	avg300;		// average pressure last 300 seconds
	count_t	total;		// total number of milliseconds
};

struct	pressure_28 {
	char	   present;	/* pressure stats supported?	*/
	char       future[3];
	struct psi_28 cpusome;	/* pressure stall info 'some'   */
	struct psi_28 memsome;	/* pressure stall info 'some'   */
	struct psi_28 memfull;	/* pressure stall info 'full'   */
	struct psi_28 iosome;	/* pressure stall info 'some'   */
	struct psi_28 iofull;	/* pressure stall info 'full'   */
};

/************************************************************************/

struct  percontainer_28 {
        unsigned long	ctid;		/* container id			*/
        unsigned long	numproc;	/* number of processes		*/

        count_t system;  	/* */
        count_t user;  		/* */
        count_t nice;  		/* */
        count_t uptime; 	/* */

        count_t physpages; 	/* */
};

struct contstat_28 {
        int             	nrcontainer;
        struct percontainer_28	cont[MAXCONTAINER_28];
};

/************************************************************************/
/*
** experimental stuff for access to local HTTP daemons
*/
#define	HTTPREQ	"GET /server-status?auto HTTP/1.1\nHost: localhost\n\n"

struct wwwstat_28 {
	count_t	accesses;	/* total number of HTTP-requests	*/
	count_t	totkbytes;	/* total kbytes transfer for HTTP-req   */
	count_t	uptime;		/* number of seconds since startup	*/
	int	bworkers;	/* number of busy httpd-daemons		*/
	int	iworkers;	/* number of idle httpd-daemons		*/
};

/************************************************************************/
struct pergpu_28 {
	char	taskstats;		// GPU task statistics supported?
	unsigned char   nrprocs;	// number of processes using GPU
	char	type[MAXGPUTYPE_28+1];	// GPU type
	char	busid[MAXGPUBUS_28+1];	// GPU bus identification
	int	gpunr;			// GPU number
	int	gpupercnow;		// processor percentage last second
					// -1 if not supported
	int	mempercnow;		// memory    percentage last second
					// -1 if not supported
	count_t	memtotnow;		// total memory in KiB
	count_t	memusenow;		// used  memory in KiB
	count_t	samples;		// number of samples
	count_t	gpuperccum;		// cumulative processor busy percentage
					// -1 if not supported
	count_t	memperccum;		// cumulative memory percentage 
					// -1 if not supported
	count_t	memusecum;		// cumulative used memory in KiB
};

struct gpustat_28 {
	int		nrgpus;		// total number of GPUs
	struct pergpu_28   gpu[MAXGPU_28];
};

/************************************************************************/
struct perifb_28 {
	char	ibname[MAXIBNAME_28];	// InfiniBand controller
	short	portnr;			// InfiniBand controller port

	short	lanes;			// number of lanes (traffic factor)
	count_t	rate;			// transfer rate in megabits/sec
	count_t	rcvb;   	    	// bytes received
	count_t	sndb;       		// bytes transmitted
	count_t	rcvp;   	    	// packets received
	count_t	sndp;       		// packets transmitted
};

struct ifbstat_28 {
	int		nrports;	// total number of IB ports
	struct perifb_28   ifb[MAXIBPORT_28];
};

/************************************************************************/
struct perllc_28 {
	unsigned char	id;
	float		occupancy;
	count_t		mbm_local;
	count_t		mbm_total;
};

struct llcstat_28 {
	unsigned char	nrllcs;	        // total number of LLC
	struct perllc_28   perllc[MAXLLC_28];
};

/************************************************************************/

struct	sstat_28 {
	struct cpustat_28	cpu;
	struct memstat_28	mem;
	struct netstat_28	net;
	struct intfstat_28	intf;
	struct memnuma_28	memnuma;
	struct cpunuma_28	cpunuma;
	struct dskstat_28  dsk;
	struct nfsstat_28  nfs;
	struct contstat_28 cfs;
	struct pressure_28	psi;
	struct gpustat_28 	gpu;
	struct ifbstat_28 	ifb;
	struct llcstat_28  llc;

	struct wwwstat_28	www;
};
