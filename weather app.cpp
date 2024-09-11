#include<iostream>
#include<cstdlib>
#include<fstream>
#include <curl/curl.h>
#include<json/json.h>
using namespace std;
class location {
protected:
	string name;
	double latitude;
	double longitude;
	static location locations[10];
	static int count;
public:
	location(string name="",double lat=0.00,double lon=0.00) {
		this ->name=name;
		latitude=lat;
		longitude=lon;
	}
	static void addlocation(string n,double lat,double lon) {
		if(count<10) {
			locations[count]=location(n,lat,lon);
			++count;
			cout<<"Location added successfully.\n";
		}
		else {
			cout<<"locations are full.\n";
		}
		return;
	}
	static void removelocation(string n) {
		for(int i=0; i<count; ++i) {
			if(locations[i].name==n) {
				for(int j=i; j<count-1; ++j) {
					locations[j]=locations[j+1];
				}
				--count;
				cout<<"Location "<<n<<" removed successfully.\n"<<endl;
			}
		}
	}
	static void listLocations() {
		if(count==0) {
			cout<<"No locations available.\n"<<endl;
		}
		else {
			for(int i=0; i<count; ++i) {
				cout<<"Location: "<<locations[i].name<<", Latitude: "<<locations[i].latitude<<", Longitude: "<< locations[i].longitude<< endl;
			}
		}
	}
};
location location::locations[10];
int location::count=0;
class WeatherVariable {
private:
	float temperature;
	float windSpeed;
public:
	void setTemperature(float temp){
		temperature=temp;
	}
	float getTemperature(){
		return temperature;
	}
	void setWindSpeed(float speed){
		windSpeed=speed;
	}
	float getWindSpeed(){
		return windSpeed;
	}
};
class WeatherForecastingSystem{
private:
	string apiUrl;
public:
	WeatherForecastingSystem(){
		apiUrl = "https://api.open-meteo.com/v1/forecast";
	}
	// to get and display weather data for a given location
	void getWeatherData(double latitude, double longitude);
};
size_t WriteCallback(void* contents, size_t size, size_t nmemb,string* userp) {
	userp->append((char*)contents, size * nmemb);
	return size * nmemb;
}
void WeatherForecastingSystem::getWeatherData(double latitude,double longitude){
	CURL* curl;
	CURLcode res;
	string readBuffer;
	curl = curl_easy_init();
	if(curl) {
		string url=apiUrl+"?latitude="+to_string(latitude)+"&longitude="+to_string(longitude)+"&hourly=temperature_2m";
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		if(res!=CURLE_OK)
			cerr<<"cURL error: "<<curl_easy_strerror(res);
		curl_easy_cleanup(curl);
	}
	// Parsing the json
	Json::Value jsonData;
	Json::CharReaderBuilder builder;
	stringstream sstr(readBuffer);
	string errs;
	if (Json::parseFromStream(builder,sstr,&jsonData,&errs)){
		const Json::Value& temperatures=jsonData["hourly"]["temperature_2m"];
		cout<<"Hourly Temperatures:"<<endl;
		for(const auto& temp : temperatures){
			cout<<temp.asFloat()<<" B0C"<<endl;
		}
	}
	else{
		cerr<<"Error parsing JSON data: "<<errs<<endl;
	}
}
int main(){
	WeatherForecastingSystem weatherSystem;
	double latitude,longitude;
	cout<<"Enter latitude: ";
	cin>>latitude;
	cout<<"Enter longitude: ";
	cin>>longitude;
	weatherSystem.getWeatherData(latitude,longitude);
	return 0;
}
