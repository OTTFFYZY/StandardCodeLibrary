template<typename T,size_t N,size_t M>
struct PrefixSum2D {
	T d[N+2][M+2];
	int n,m;
	void init(int n_,int m_) { n=n_; m=m_; }
	//     ymin           ymax
	// xmin +--------------+
    //      |              |
	//      |              |
	// xmax +--------------+
	void add(int xmin,int xmax,int ymin,int ymax,int v) {
		d[xmin][ymin]+=v;
		d[xmax+1][ymin]-=v;
		d[xmin][ymax+1]-=v;
		d[xmax+1][ymax+1]+=v;
	}
	void cal() {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1];
	}
	T* operator[](int r) { return d[r]; }
};
PrefixSum2D<> ps;