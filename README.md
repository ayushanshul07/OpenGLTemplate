# OpenGLTemplate

This repo helps you in setting up a OpenGL Template for Desktop and Web. You can further build upon it.

## SetUp step

Use the package manager [homebrew](https://brew.sh/) to install necessary libraries.

```bash
brew install glfw
brew install glew
```

## Usage
* For Desktop
```bash
mkdir build/
cd build/
cmake ..
make --build .
./App
```

* For Web
```bash
mkdir build/
cd build/
[Source emcmake paths]
emcmake cmake ..
make --build .
./App
```

## Contributing

Feel free to create a pull request for adding core changes which you feel appropriate for the template.

## License
[MIT](https://choosealicense.com/licenses/mit/)
