// ROOT macro to count entries in a TTree from a CVMFS file
// and write the count to a text file for reproducibility testing.
void count_events() {
    // Use the cernstaff.root tutorial file shipped with ROOT itself.
    // gROOT->GetTutorialDir() gives the correct path regardless of ROOT version.
    TString filename = TString(gROOT->GetTutorialDir()) + "/hsimple.root";

    auto rdf = ROOT::RDataFrame("ntuple", filename);
    int count = rdf.Count().GetValue();    
    std::cout << count << std::endl;
}
