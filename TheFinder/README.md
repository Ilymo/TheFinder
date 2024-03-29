# The Finder
#### Video Demo:  <URL HERE>
#### Description:

## Summary
The Finder is a web app that suggests movies or Japanese anime.

On the **"Home"** page, you have two choices: **"The Movie Finder"** or **"The Anime Finder"**.

Click on one of them, and you'll be redirected to the appropriate page.


Both of them have the same logic and have two ways of searching:

### First search method:

On the left, there is the tag research:

- First, you must choose (via the select input) at least one "genre" tag, up to three.

- After that, you can choose (via the radio button input) the period of the movie/anime release. By default, "1990+" is selected.

- Last, you can choose the "rate" (via another radio button input) of the movie/anime you're looking for. By default, "0+" is selected.

### Second search method:

On the right, there is the "reference" research:

- First, you must type (via the text input) the movie/anime that you want as a reference.

- After that, you can choose (via the radio button input) the period of the movie/anime release. By default, "1990+" is selected.

- Last, you can choose the "rate" (via another radio button input) of the movie/anime you're looking for. By default, "0+" is selected.

### Result:

When you're done with one of those search methods, press **"Give me"** button, and you'll be redirected to the **"Result"** page, where the search results will be displayed on cards.

You can then press the **"Give me 10 others"** button at the top or bottom of the page, and the app will suggest 10 other movie/anime with those same criteria (if there are more than 10 movies/anime that respect those criteria).

At the top and bottom of the result page, you can also:

- Press **"Back"** button to go back to the previous search page.

- Press **"Home"** button, and you'll be redirected to the Home page.




## Explanation

### Environment

The app has been written with Python in the CS50 codespace, it uses the SQL module from cs50 library and flask.

### index.html

The home page displays two buttons, which both call the respective route.

### movie.html and anime.html

When the `movie.html` or `anime.html` route is called, it will get:
- All the tags from a list of tags `MOVIE_TAGS` or `ANIME_TAGS`.
- Movie/anime names from the database via an SQL query

Then, render `movie.html` or `anime.html`, pass in and display this information into the **"select input"** and the **"text field input"**

When **"Give me"** button is pressed, it submits the chosen criteria via `Get` method to the `movieresult.html` or `animeresult.html` route.


### movieresult.html and animeresult.html

When the `movieresult.html` or `animeresult.html` route is called, it will:

**For tag research:**
- Check if tag1 is submitted and exists in `MOVIE/ANIME_TAGS`, also check if `year` and `rate` have been submitted.
- Get the tags with `request.args.get("tag1") tag2 and tag3` and store them in `tag1, tag2, tag3` variables.
- Get the year with `request.args.get("year")`and store the value in `year` variable.
- Get the rate with `request.args.get("rate")`and store the value in `rate` variable.
- Then execute SQLite query on the database with this information, it will generate a list of 10 movie/anime and store them into `movie` or `anime` variable.

If the `movie` or `anime` variable is empty, it will render `noresult.html` and display the message **"Sorry but there is no result :("**

Otherwise, it will render `result.html`, pass in the `movie` or `anime` variable, and display them on cards.

**For reference research:**
- Check if `reference` is submitted, also check if `year` and `rate` have been submitted.
- Get the reference with `request.args.get("reference")` and store the value in `reference` variable.
- Execute SQLite query with `reference` as name, get associated genres and store them in `tags` variable.
- Get the year with `request.args.get("year")`and store the value in `year` variable.
- Get the rate with `request.args.get("rate")`and store the value in `rate` variable.
- Separate tags and remove "," with `str.split(tags[0]["Genre"].replace(",", ""))` from `tags` variable and store them into `unique_tag` list.
- Count the number of tags with `len(unique_tag)` and store the value in `tag_nb`.
- Then, depending on `tag_nb`, it will execute SQLite query on the database with this information, it will generate a list of 10 movie/anime and store them in `movie` or `anime` variable

If the `movie` or `anime` variable is empty, it will render `noresult.html` and display the message **"Sorry but there is no result :("**

Otherwise, it will render `result.html`, pass in the `movie` or `anime` variable, and display them on cards.

If neither `tag1`+`year`+`rate` nor `reference`+`year`+`rate` have been submitted, it will render `noresult.html`.



#### CSS resources:

The [Select Input](https://codepen.io/vkjgr/pen/VYMeXp), [Button](https://uiverse.io/adamgiebl/rare-moose-45),
[Radio Button](https://uiverse.io/gharsh11032000/moody-dog-23), [Text Field](https://codepen.io/webcrafterscz/pen/WLxzyQ)
that I modified and used.

Cards on result page were been made by myself.

#### Database:
CSV files downloaded via: [db movie](https://www.kaggle.com/datasets/disham993/9000-movies-dataset), [db anime](https://www.kaggle.com/datasets/dbdmobile/myanimelist-dataset) and inserted into media.db








