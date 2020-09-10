public <T1, T2> class JavaPair {
	public T1 fi;
	public T2 se;
	public JavaPair(T1 first, T2 second) {
		fi = first;
		se = second;
	}
	@Override
	public boolean equals(JavaPair<T1, T2> B) {
		return fi == B.fi && se == B.fi;
	}
	@Override
	public long hashCode() {
		return fi.hashCode() ^ se.hashCode();
	}
}