
Name : Jared Muralt

Notes:
I chose to keep most class variables public because I don't think getters and setters are necessary for this.
I kept most of the GPS related stuff in one 'gps.h' file to make the proect less cluttered and make the include list smaller.
Just to make sure, I went through a map to make sure the sorting and distance calculations were accurate.


Post presentation Notes:
I realized that my longitude may be calculating the opposite way (starting at Hawaii). Therefore the total distance longitude is probably
off a bit. The problem would be located in compareByLongitude.h sorting the Cardinal.
