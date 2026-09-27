#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <memory>                            // <memory> = library for smart pointers (unique_ptr, make_unique)
#include <vector>                            // <vector> = library for dynamic arrays (vector)
#include <string>                            // <string> = library for handling text data (string)

using namespace std;                         // using namespace std = allows using cout, vector, string directly without std:: prefix


class Media {                                // class = keyword to define a blueprint/type
                                             // Media = base class representing general media

public:                                      // public = accessible from outside the class

    virtual void play() const = 0;           // virtual = enables runtime polymorphism
                                             // void = function does not return any value
                                             // play() = starts playing the media
                                             // const = function does not modify member variables
                                             // = 0; = pure virtual function, making Media an abstract class

    virtual void pause() const = 0;          // pure virtual function to pause the media

    virtual void stop() const = 0;           // pure virtual function to stop the media

    virtual void showDetails() const = 0;    // pure virtual function to display media details

    virtual ~Media() = default;              // virtual destructor ensures proper destruction of derived objects
                                             // = default; = compiler generates the default destructor
};                                           // ; = ends Media class declaration


class Audio : public Media {                 // Audio = derived class inheriting publicly from Media
                                             // : = inheritance operator
                                             // public Media = publicly inherits from Media

private:                                     // private = accessible ONLY inside Audio class
    string title;                            // string = stores the title of the audio

public:                                      // public = accessible from outside the class

    Audio(string t) : title(t) {}            // constructor initializes the audio title
                                             // string t = parameter storing the title
                                             // : title(t) = member initializer list initializes title

    void play() const override {             // override = implements the play() function of Media
        cout << "Playing audio: " << title << endl; // displays the audio currently playing
    }                                        // ends the play() function

    void pause() const override {            // override = implements the pause() function of Media
        cout << "Pausing audio: " << title << endl; // displays the paused audio
    }                                        // ends the pause() function

    void stop() const override {             // override = implements the stop() function of Media
        cout << "Stopping audio: " << title << endl; // displays the stopped audio
    }                                        // ends the stop() function

    void showDetails() const override {      // override = implements showDetails() of Media
        cout << "Audio: " << title << endl;  // displays audio details
    }                                        // ends the showDetails() function
};                                           // ; = ends Audio class declaration


class Video : public Media {                 // Video = derived class inheriting publicly from Media
                                             // public Media = inherits from the Media base class

private:                                     // private = accessible ONLY inside Video class
    string title;                            // stores the title of the video

public:                                      // public = accessible from outside the class

    Video(string t) : title(t) {}            // constructor initializes the video title

    void play() const override {             // override = implements the play() function
        cout << "Playing video: " << title << endl; // displays the video currently playing
    }                                        // ends the play() function

    void pause() const override {            // override = implements the pause() function
        cout << "Pausing video: " << title << endl; // displays the paused video
    }                                        // ends the pause() function

    void stop() const override {             // override = implements the stop() function
        cout << "Stopping video: " << title << endl; // displays the stopped video
    }                                        // ends the stop() function

    void showDetails() const override {      // override = implements showDetails() of Media
        cout << "Video: " << title << endl;  // displays video details
    }                                        // ends the showDetails() function
};                                           // ; = ends Video class declaration


class Image : public Media {                 // Image = derived class inheriting publicly from Media
                                             // public Media = inherits from the Media base class

private:                                     // private = accessible ONLY inside Image class
    string title;                            // stores the title of the image

public:                                      // public = accessible from outside the class

    Image(string t) : title(t) {}            // constructor initializes the image title

    void play() const override {             // override = implements the play() function
        cout << "Displaying image: " << title << endl; // displays the image
    }                                        // ends the play() function

    void pause() const override {            // override = implements the pause() function
        cout << "Pausing image: " << title << endl; // displays the paused image
    }                                        // ends the pause() function

    void stop() const override {             // override = implements the stop() function
        cout << "Stopping image: " << title << endl; // displays the stopped image
    }                                        // ends the stop() function

    void showDetails() const override {      // override = implements showDetails() of Media
        cout << "Image: " << title << endl;  // displays image details
    }                                        // ends the showDetails() function
};                                           // ; = ends Image class declaration


int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution in C++ programs

    vector<unique_ptr<Media>> mediaItems;    // vector = dynamic array
                                             // unique_ptr<Media> = smart pointer to base-class Media objects
                                             // mediaItems = stores different media objects

    mediaItems.push_back(make_unique<Audio>("Morning Song")); // creates an Audio object and adds it to the collection

    mediaItems.push_back(make_unique<Video>("Nature Documentary")); // creates a Video object and adds it to the collection

    mediaItems.push_back(make_unique<Image>("Mountain Photo")); // creates an Image object and adds it to the collection

    cout << "=== Media Player ===" << endl;  // displays the title of the media player

    for (const auto& media : mediaItems) {   // for = range-based loop through every media object
                                             // const auto& = read-only reference to each smart pointer
                                             // media = represents the current media object

        media->showDetails();                // calls the appropriate showDetails() using runtime polymorphism

        media->play();                       // calls the appropriate play() function using runtime polymorphism

        media->pause();                      // calls the appropriate pause() function using runtime polymorphism

        media->stop();                       // calls the appropriate stop() function using runtime polymorphism

        cout << endl;                        // prints a blank line between media items
    }                                        // ends the for loop

    return 0;                                // return 0 = signals successful program execution
}                                            // ends the main() function