
    ve<pr<z, z>> ds;
    for(z i = 2; i * i <= k; i++) {
        z cnt = 0;
        while(k % i == 0) {cnt++; k/=i;}
        ds.pb(mp(i, cnt));
    }
    if(k != 1) ds.pb(mp(k, 1));
    fo(i, ds.size()) {
        ds[i].sc = (ds[i].sc + m - 1) / m;
    }
    long long ans = 1;
    fo(i, ds.size()) {
        fo(j, ds[i].sc) {
            ans *= (long long)ds[i].fs;
        }
    }
    cout << ans << nl;