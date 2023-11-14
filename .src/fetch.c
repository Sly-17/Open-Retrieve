#include <stdio.h>

#include <stdlib.h>

#include <curl/curl.h>


#define TEMP_FILE_PATH "./temp.html"

FILE * fptr;

// Callback function to handle the received data

size_t write_callback(void * contents, size_t size, size_t nmemb, void * userp) {

  size_t realsize = size * nmemb;

  fprintf(fptr, "%.*s", (int) realsize, (char * ) contents);

  return realsize;

}

int main(int argc, char * argv[]) {

  // Initialize libcurl

  CURL * curl = curl_easy_init();

  fptr = fopen(TEMP_FILE_PATH, "w");

  if (curl) {

    // Set the URL to fetch

    const char * url = argv[1];

    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the callback function to handle the received data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);


    CURLcode res = curl_easy_perform(curl);


    if (res != CURLE_OK) fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

    // Cleanup
    curl_easy_cleanup(curl);

  }

  fclose(fptr);

  return 0;

}
