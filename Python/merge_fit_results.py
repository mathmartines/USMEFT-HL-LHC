"""Merge the results from the fit."""

import os
import json

if __name__ == "__main__":
    # Path where the files are stored
    folderpath = "/home/martines/work/PhD_Projects/USMEFT-HL-LHC/json_files/Wprime/d8"

    # List with all files inside the directory
    all_fit_files = [filename for filename in os.listdir(folderpath) if ".json" in filename]

    # Get the names of the WCs
    wc_names = set([filename.split("-")[0] for filename in all_fit_files])

    # Initializes the dictionary for each WC
    fit_results = {coef_name: [] for coef_name in wc_names}

    # Reads the content of all the files
    for filename in all_fit_files:
        print(filename)
        # Name of the WC
        coef_name_file, *_ = filename.split("-")
        # Reads the content of the file
        with open(f"{folderpath}/{filename}") as file_:
            file_content = json.load(file_)
            # Updates the dictionary with the fit results
            fit_results[coef_name_file].append(file_content)

    for coef, results in fit_results.items():
        with open(f"{folderpath}/../../../FitStats/Wprime/d8/{coef}.json", "w") as file_:
            json.dump(results, file_, indent=4)
