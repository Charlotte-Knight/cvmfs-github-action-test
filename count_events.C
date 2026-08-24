// ROOT macro to count entries in a TTree from a CVMFS file
// and write the count to a text file for reproducibility testing.
void count_events() {
    // Use the cernstaff.root tutorial file shipped with ROOT itself.
    // gROOT->GetTutorialDir() gives the correct path regardless of ROOT version.
    TString filename = TString(gROOT->GetTutorialDir()) + "/tree/cernstaff.root";
    const char *treename = "T";
    const char *outfile  = "output.txt";

    TFile *f = TFile::Open(filename.Data());
    if (!f || f->IsZombie()) {
        fprintf(stderr, "ERROR: Cannot open %s\n", filename.Data());
        exit(1);
    }
    TTree *t = (TTree *)f->Get(treename);
    if (!t) {
        fprintf(stderr, "ERROR: Cannot find tree '%s' in %s\n", treename, filename.Data());
        f->Close();
        exit(1);
    }
    Long64_t n = t->GetEntries();
    f->Close();

    FILE *out = fopen(outfile, "w");
    if (!out) {
        fprintf(stderr, "ERROR: Cannot write %s\n", outfile);
        exit(1);
    }
    fprintf(out, "%lld\n", n);
    fclose(out);

    printf("Number of entries: %lld\n", n);
}
