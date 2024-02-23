# The Finder
#### Video Demo:  <URL HERE>
#### Description:

## Summary
The Finder is a web app that suggest movie or japanese anime.

On the **Home** page you have two choice, **The Movie Finder** or **The Anime Finder**.

Click on one of them and you'll be redirected to the appropriate page.


Both of them have the same logic and have two ways of searching:

### First search method:

On the left, there is the tag research:

- First, you must choice (via the select input) at least one "genre" tag, up to three.

- After that, you can choice (via the radio button input) the period of the movie/anime release. By default, "1990+" is selected.

- Last, you can choice the "rate" (via another radio button input) of the movie/anime you're looking for. By default, "0+" is selected.

### Second search method:

On the right, there is the "reference" research:

- First, you must type (via the text input) the movie/anime that you want as reference.

- After that, you can choice (via the radio button input) the period of the movie/anime release. By default, "1990+" is selected.

- Last, you can choice the "rate" (via another radio button input) of the movie/anime you're looking for. By default, "0+" is selected.

### Result:

When you're done with one of those search methods, press **Give me** button and you'll be redirected to the **Result** page where the search result will be display into card.

You can then press the **Give me 10 others** button on top or bottom of the page and the app will suggest 10 other movie/anime with those same criterias (if there is more than 10 movie/anime that respect those criterias).

On top and bottom of the result page you can also:

- Press **Back** button to go back on the previous search page.

- Press **Home** button and you'll be redirected to the Home page.




## Explanation

### Environnement

The app has been writted with python into the CS50 codespace, it use the SQL module from cs50 library and flask.

### index.html

The home page display 2 button and redirect to the appropriate page

### movie.html and anime.html

When the `movie.html` or `anime.html` route is called, it will get:
- all the tags from a list of tags `MOVIE_TAGS` or `ANIME_TAGS`.
- movie/anime names from the database via an SQL query

Then, it will display them into the **select input** and the **text field input**

When **Give me** button is press, it submit the choiced criterias via `Get` method to the `result.html`page.


#### CSS ressources:

The [Select Input](https://codepen.io/vkjgr/pen/VYMeXp), [Button](https://uiverse.io/adamgiebl/rare-moose-45),
[Radio Button](https://uiverse.io/gharsh11032000/moody-dog-23), [Text Field](https://codepen.io/webcrafterscz/pen/WLxzyQ)
that I modified and used.

#### Database:
[db movie](https://www.kaggle.com/datasets/disham993/9000-movies-dataset), [db anime](https://www.kaggle.com/datasets/dbdmobile/myanimelist-dataset)

checkbox:
https://uiverse.io/adamgiebl/curly-lizard-40 (ready in tempo.txt)







