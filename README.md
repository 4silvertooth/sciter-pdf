# Sciter-PDF

Sciter binding for [libharu pdf library](https://github.com/libharu/libharu)

**Installing**

You will need both `cmake` and `premake5` to build this project, `cmake` to `configure` libharu and `premake5` to generate `sicter-pdf` project. 

Download cmake from [https://cmake.org/download/](https://cmake.org/download/)

Download premake5 from [https://premake.github.io/](https://premake.github.io/)

```sh
#cloning sciter-pdf repo and libharu as submodule
git clone --recursive https://github.com/4silvertooth/sciter-pdf

#cd into the cloned repo
cd sciter-pdf

#cmake just require to config libharu, no need to build it.
cmake -S ./sub-modules/libharu -B ./sub-modules/libharu/build

#will generate project to build both
./premake5 [ACTION] --sciter="PATH/TO/SCITER-SDK"
```
&nbsp;
where `[ACTION]` is your prefered ACTION supported by premake5, use `./premake5 --help` for supported actions, and `"PATH/TO/SCITER-SDK"` is well path to sciter-sdk. 

Open the generated project from `/build` and compile.

**Usage** Sciter

```html
<html>
<head>

<script type="text/tiscript">
include library "sciter-pdf";

event click $(button) {
  Doc.newDoc();

  const page = Doc.addPage();
  page.setSize(page.SIZE_A4, page.PORTRAIT);
  const h = page.getHeight();

  const font = Doc.getFont("Helvetica", null);
  page.setFontAndSize(font, 12);

  page.beginText();
  page.textRect(
    {
      left: 20, 
      top: h-20, 
      right: 100, 
      bottom: 50
    }, 
    "HELLO PDF", 
    page.TALIGN_LEFT
  );
  page.endText();

  Doc.save(URL.toPath(self.url('test.pdf')));
  Sciter.launch(self.url('test.pdf'));

}

</script>
</head>
<body>
  <button>CLICK TO GENERATE PDF</button>
</body>
</html>
```

**Usage** Sciter.JS

```html
<html>
<head>

<script type="text/tiscript">
include library "sciter-pdf";

event click $(button) {
  Doc.newDoc();

  const page = Doc.addPage();
  page.setSize(page.SIZE_A4, page.PORTRAIT);
  const h = page.getHeight();

  const font = Doc.getFont("Helvetica", null);
  page.setFontAndSize(font, 12);

  page.beginText();
  page.textRect(
    {
      left: 20, 
      top: h-20, 
      right: 100, 
      bottom: 50
    }, 
    "HELLO PDF", 
    page.TALIGN_LEFT
  );
  page.endText();

  Doc.save(URL.toPath(self.url('test.pdf')));
  Sciter.launch(self.url('test.pdf'));

}

</script>
</head>
<body>
  <button>CLICK TO GENERATE PDF</button>
</body>
</html>
```
```