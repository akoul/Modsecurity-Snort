#Introduction

This repo contains the snort files which will be used to extract and send data to libmodsecurity interface.

#Installation guide

1. First build libModSecurity in your system. [Compilation recipes]
(https://github.com/SpiderLabs/ModSecurity/wiki/Compilation-recipes)

2. Build snort++ in your system. [Compilation recipes]
(https://github.com/snortadmin/snort3#build-snort)

3. Try running snort in your system to see if it is correctly installed and working properly. [Testing]
(https://github.com/snortadmin/snort3#run-snort)

4. Build the examples using instructions from `snort3/extra/README`

5. To extract http data from a buffer, you will need a trace file having http data. An example file is also attached in the repo

6. Run the following command in your terminal:
   `snort -c $my_path/etc/snort/snort.lua --plugin-path $my_path/lib/snort_extra -A alert_ex -r /path/to/my.pcap`

7. A data.log file must be created in your home directory. The file contains extracted data from the trace file you used as input to the snort system.

#TO-DO

1. Extract remaining fields from the snort inspector.

2. Send the remaining fields to libmodsecurity for processing.

3. Build the connector to utilise the interface.

#Disclaimer
This is an early example of snort inspector. You can change the file name and location along with corresponding changes in the Makefile.

