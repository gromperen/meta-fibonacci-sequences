

vector<Int_t> memoQ;
vector<Int_t> memoC;
vector<Int_t> memoB;
vector<Int_t> memoH;

Int_t Q(Int_t n) {
	if (memoQ[n]) return memoQ[n];
	return memoQ[n] = Q(n - Q(n-1)) + Q(n - Q(n-2));
}

void iterate_Q(Int_t n) {
	for (int i = 3; i <= n; ++i) {
		memoQ[i] = memoQ[i - memoQ[i-1]] + memoQ[i - memoQ[i-2]];
		// cout << memoQ[i] << " ";
	}
}

void iterate_C(Int_t n) {
	for (int i = 3; i <= n; ++i) {
		memoC[i] = memoC[memoC[i-1]] + memoC[i - memoC[i-1]];
	}
}

void iterate_B(Int_t n) {
	for (int i = 3; i <= n; ++i) {
		memoB[i] = memoB[memoB[i-1]] + memoB[i - memoB[i-2] - 1];
	} }

void geb() {
	Int_t n;
	cout << "n = ";
	cin >> n;
	memoQ.resize(n+105);
	memoC.resize(n+105);
	memoB.resize(n+105);
	memoH.resize(n+105);
	memoC[0] = memoC[1] = memoC[2] = 1;
	memoQ[0] = memoQ[1] = memoQ[2] = 1;
	memoB[0] = memoB[1] = memoB[2] = 1;

	iterate_Q(n+100);
	iterate_C(n+100);
	iterate_B(n+100);
	cout << memoQ[n] << endl;
	cout << memoC[n] << endl;
	cout << " OK " << endl;
	// cout << Q(n) << endl;
	Int_t npoints = min(100000, n);
	Int_t stepsize = n / npoints;
	Int_t Qx[npoints], Qy[npoints];
	for (int i = 0; i < npoints; ++i) {
		Int_t x = i*stepsize;
		Qx[i] = x;
		Qy[i] = memoQ[x] - x/2;
		//cout << Qx[i] << " " << Qy[i] << endl;
	}
	Int_t Cx[npoints], Cy[npoints];
	for (int i = 0; i < npoints; ++i) {
		Int_t x = i*stepsize;
		Cx[i] = x;
		Cy[i] = memoC[x] - x/2;
		//cout << Qx[i] << " " << Qy[i] << endl;
	}

	Int_t Hx[npoints], Hy[npoints];
	for (int i = 0; i < npoints; ++i) {
		Int_t x = i*stepsize;
		Hx[i] = x;
		Hy[i] = (memoC[x] - memoQ[x]);
		//cout << Qx[i] << " " << Qy[i] << endl;
	}

	//auto bgr = new TGraph();
	Int_t Bx[npoints], By[npoints];
	for (int i = 0; i < npoints; ++i) {
		Int_t x = i*stepsize;
		Bx[i] = x;
		By[i] = (Int_t)(1000.0/x*memoB[x]);
		//bgr->AddPoint(x, 1000.0 * memoB[(int)x] / x) ;
		//cout << Qx[i] << " " << Qy[i] << endl;
		//cout << Bx[i] << " " << By[i] << endl;
	}


	for (int i = 0; i <= n; ++i) {
		memoH[i] = memoC[i] - memoQ[i];
	}

	TGraph2D *gr6 = new TGraph2D();

	Int_t pc_x[npoints], pc_y[npoints], pc_z[npoints];
	for (int i = 0; i < npoints; ++i) {
		Int_t x = i*stepsize;
		//pc_x[i] = memoH[x]; - x/2;
		//pc_y[i] = memoH[x+1]; - x/2;
		//pc_z[i] = memoH[x+2];
		pc_x[i] = x;
		pc_y[i] = memoH[x];
		pc_z[i] = memoH[x+1];

		gr6->SetPoint(i, pc_x[i], pc_y[i], pc_z[i]);
	}

	TGraph2D *gr7 = new TGraph2D();

	for (int i = 0; i < npoints; ++i) {
		Int_t x = i*stepsize;
		//pc_x[i] = memoH[x]; - x/2;
		//pc_y[i] = memoH[x+1]; - x/2;
		//pc_z[i] = memoH[x+2];
		Int_t curx = memoB[x];
		Int_t cury = memoB[x+1];
		Int_t curz = memoB[x+2];

		gr7->SetPoint(i, curx, cury, curz);
	}

	TGraph* gr1 = new TGraph(npoints, Qx, Qy);
	TGraph* gr2 = new TGraph(npoints, Cx, Cy);
	TGraph* gr3 = new TGraph(npoints, Hx, Hy);
	TGraph* gr4 = new TGraph(npoints, Bx, By);
	TGraph* gr5 = new TGraph(npoints, pc_x, pc_y);

	//bgr->Draw("AP");
	//gr4->Draw("APL");
	//gr2->Draw("P");
	//gr3->Draw("AP");
	gr7->Draw("P");
}
