document.addEventListener('DOMContentLoaded', function(){
    let button = document.querySelector('#surprise');
    button.addEventListener('click', function(){
        if (rick.style.display == 'none'){
            rick.style.display = 'inline-block';
        }
        else {
            rick.style.display = 'none';
        }
    })
})
