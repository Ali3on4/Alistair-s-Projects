#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <portaudio.h>
#include <dsound.h>
#include <stdlib.h>
#include <sndfile.h>
#include <mmsystem.h>
#include <windows.h>
#include <stdbool.h>
#define SAMPLE_RATE 44100
#define NUM_SECONDS 60
#define paClipOff ((PaStreamFlags) 0x00000001)

typedef struct {
	char name[100];
	char songs[20][51];
	int nSongs;
}Playlist;

void playwav(char wavfile[100] ) {

	PaError err;

	SF_INFO sfInfo;
	SNDFILE* sndFile = sf_open(wavfile, SFM_READ, &sfInfo);

	const sf_count_t bufferSize = sfInfo.frames * sfInfo.channels;
	float* buffer = (float*)malloc(bufferSize * sizeof(float));
	sf_count_t framesRead = sf_readf_float(sndFile, buffer, sfInfo.frames);

	if (framesRead < sfInfo.frames)
	{
		printf("Error reading WAV file\n");
		sf_close(sndFile);
		free(buffer);
	}

	err = Pa_Initialize();

	if (err != paNoError) {
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}

	PaStream* stream;

	err = Pa_OpenDefaultStream(&stream, 0, sfInfo.channels, paFloat32, sfInfo.samplerate, paFramesPerBufferUnspecified, NULL, NULL);


	if (sndFile == NULL) {
		printf("Error Opening File!");
		
	}



	if (err != paNoError)
	{
		printf("Error Opening Stream\n\n");
		
	}

	err = Pa_StartStream(stream); 

	if (err != paNoError)
	{
		printf("Error Starting Stream\n\n");
		
	}

	err = Pa_WriteStream(stream, buffer, sfInfo.frames);

	if (err != paNoError)
	{
		printf("Error Playing Stream\n\n");
		
	}

	Pa_Sleep(NUM_SECONDS * 1000); 

	err = Pa_StopStream(stream); 

	if (err != paNoError)
	{
		printf("Error Stopping Stream\n\n");
		
	}

	err = Pa_CloseStream(stream);

	if (err != paNoError)
	{
		printf("Error Closing Stream\n\n");
		
	}

	Pa_Terminate();
	if (err != paNoError)
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}

	return;

}

int playmp3(char mp3file[100]) {

	PaError err;

	printf("\n%s\n", mp3file);

	DWORD result = mciSendStringA(mp3file, NULL, 0, NULL);
	if (result != 0) {
		mciGetErrorStringA(NULL,0,NULL);
		printf("\nFailed to open the MP3 file.\n");
		return 1;
	}


	result = mciSendStringA("play mp3", NULL, 0, NULL);
	if (result != 0) {
		printf("\nFailed to play the MP3 file.\n");
		mciSendStringA("close mp3", NULL, 0, NULL);
		return 1;
	}


	char status[128];
	do {
		mciSendStringA("status mp3 mode", status, sizeof(status), NULL);
	} while (strcmp(status, "stopped") != 0);


	mciSendStringA("close mp3", NULL, 0, NULL);

	return 0;
}


/*
void loadmusic(char song[]) {

	const char* mp3File = song;
	if (!isPlaying) {
		isPlaying = true;
		playmp3(mp3File);
		isPlaying = false;
	}
}*/


void playlist(Playlist** playlists, int* nPlaylists) {

	int i = 0;
	char playlistname[51];
	char aux;
	char useranswers;
	char listOfSongs[20][51];
	int numberOfSongs = 0;

	printf("What would you like to call this playlist?\n");
	scanf("%39[^\n]", playlistname);
	scanf("%c", &aux);

	printf("Type 0 when you're finished adding songs\n\n");
	while (i < 20) {

		printf("Song number %d\n", i + 1);
		scanf("%39[^\n]", listOfSongs[i]);
		scanf("%c", &aux);

		printf("Would you like to leave? (y/n)\n");
		scanf("%c", &useranswers);
		scanf("%c", &aux);

		numberOfSongs++;

		if (useranswers == 'y')
			break;

		i++;
	}

	printf("List of songs: \n");

	for (int j = 0; j < numberOfSongs; j++) {
		printf("%s\n", listOfSongs[j]);

	}

	if (*nPlaylists == 0) {

		*playlists = (Playlist*)malloc(sizeof(Playlist));
		strcpy((*playlists)->name, playlistname);
		for (int j = 0; j < numberOfSongs; j++) {
			strcpy((*playlists)->songs[j], listOfSongs[j]);
		}

		(*playlists)->nSongs = numberOfSongs;

		(*nPlaylists)++;

	} 

	else {
		*playlists = (Playlist*)realloc(*playlists, sizeof(Playlist) * (*nPlaylists + 1));
		(*nPlaylists)++;
		strcpy((*playlists)[*nPlaylists - 1].name, playlistname);
		for (int j = 0; j < numberOfSongs; j++) {
			strcpy((*playlists)[*nPlaylists - 1].songs[j], listOfSongs[j]);
		}
		(*playlists)[*nPlaylists - 1].nSongs = numberOfSongs;
	}
}

void viewplaylist(Playlist* playlists, int* nPlaylist) {

	int i = 0;
	int j = 0;

	for (j = 0; j < *nPlaylist; j++) {
		printf("Playlist number %d: %s\n", (j + 1), playlists[j].name);
		printf("List of songs:\n");
		for (i = 0; i < playlists[j].nSongs; i++) {
			printf("Song %d:%s\n", i + 1, playlists[j].songs[i]);
		}
	}
	
}

void playplaylist(Playlist* playlists, int* nPlaylist) {

	int i = 0;
	int j = 0;
	char userplayplaylist[100];
	char aux{};
	char resultString[50];
	int foundPlaylist = 0;

	if (*nPlaylist == 1) {
		printf("\nPlaying playlist %s", playlists[0].name);

		for (i = 0; i < playlists[0].nSongs; i++) {
			strcat(playlists->songs[i], ".mp3"); // resultString = open\"C:\\Users\\Alist\\Desktop\\Music\\SIRENS mix 1.mp3"

			sprintf(resultString, "open \"C:\\\\Users\\\\Alist\\\\Desktop\\\\Music\\\\%s\" type mpegvideo alias mp3", (playlists)->songs[i]);

			//printf("\n%s", resultString[i]);

			playmp3(resultString);

			resultString[0] = '\0';

			//printf("\n%s", playlists[0].songs[i]);
		}
	}

	else {

		printf("\nWhich playlist would you like to play?\n");
		for (j = 0; j < *nPlaylist; j++) {
			printf("Playlist number %d: %s\n", (j + 1), playlists[j].name);
		}

		scanf("%s", userplayplaylist);

		while (i < *nPlaylist) {
			if (strcmp(playlists[i].name, userplayplaylist) == 0) { //if we find it
				foundPlaylist = 1;
				break;
			}
			i++;
		}

		if (foundPlaylist == 1) {
			printf("\nPlaying playlist %s", playlists[i].name);


			for (int j = 0; j < playlists[i].nSongs; j++) {
				strcat(playlists[i].songs[j], ".mp3"); // resultString = open\"C:\\Users\\Alist\\Desktop\\Music\\SIRENS mix 1.mp3"

				sprintf(resultString, "open \"C:\\\\Users\\\\Alist\\\\Desktop\\\\Music\\\\%s\" type mpegvideo alias mp3", playlists[i].songs[j]);

				//printf("\n%s", resultString[i]);

				playmp3(resultString);

				resultString[0] = '\0';

			}
		}
		else {
			printf("There is no playlist with that name\n");
		}

		
	}
}

int filechecker(char song[100]) {
	int i = 0;
	char file[] = {".mp3"};

	char* workingif = strstr(song, file);
	
		if (workingif != NULL) {
//checks if file is an MP3//

			printf("FILE IS A MP3\n");

			PaError err;

			DWORD result = mciSendStringA(song, NULL, 0, NULL);
			if (result != 0) {
				printf("Failed to open the MP3 file.\n");

				return -1;
			}

	}

	

		//else {
//if not must be a wav//

		//	printf("FILE IS A WAV\n");

	//	}
	
}

void menu() {
	int user_choice = 0;
	char songName[100];
	char aux;
	char listofsongs[20][51];
	Playlist* playlists = NULL;
	int nPlaylists{};
	int numberofsongs = 0;
	char resultString[256];
	

	while (user_choice != 4) {
		printf("1 - Play song\n");
		printf("2 - Create Playlist\n");
		printf("3 - View Playlists\n");
		printf("4 - Play Playlist\n");
		printf("5 - Exit\n");

		printf("Please enter an option: ");
		scanf("%d", &user_choice);
		scanf("%c", &aux);


		if (user_choice == 1) {

			printf("Please choose which song you would like to play.");

			scanf("%99[^\n]", songName);
			scanf("%c", &aux);

			strcat(songName, ".mp3"); // resultString = open\"C:\\Users\\Alist\\Desktop\\Music\\SIRENS mix 1.mp3"

			sprintf(resultString, "open \"C:\\\\Users\\\\Alist\\\\Desktop\\\\Music\\\\%s\" type mpegvideo alias mp3", songName);

			//strcat(resultString, "C:\\\\Users\\\\Alist\\\\Desktop\\\\Music\\\\"); // open"C:\\Users\\Alist\\Desktop\\Music\\

			//strcat(resultString, songName); // resultString = open"C:\\Users\\Alist\\Desktop\\Music\\SIRENS mix 1

			//strcat(resultString, " type mpegvideo alias mp3\"");

			//filechecker(resultString);
			
			playmp3(resultString);

			printf("Would you like to play another song?");

		}

		else if (user_choice == 2) {
			playlist(&playlists, &nPlaylists);
		}

		else if (user_choice == 3) {
			viewplaylist(playlists, &nPlaylists);
		}

		else if (user_choice == 4) {
			
			printf("%d", nPlaylists);
			
			playplaylist(playlists, &nPlaylists);

		}
		else if (user_choice == 5) {
			break;
		}
	}
}

int main() {
	
	//loadmusic();

	menu();

	//playmp3("C:\\Users\\Alist\\Desktop\\Music\\SIRENS mix 1.mp3");


	return 0;
	
}

	