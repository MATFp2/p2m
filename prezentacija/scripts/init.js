/**
 * Created with JetBrains PhpStorm.
 * User: andjelka
 * Date: 2/17/15
 * Time: 7:23 PM
 * To change this template use File | Settings | File Templates.
 */

$(function() {

    $( "#kartice" ).tabs({
        collapsible: false,
        // pamcenje selektovane kartice
        activate: function( event, ui ) {
            window.location.hash = $("#kartice").tabs("option","active")+"_tab"
            window.sessionStorage.setItem("selektovana_kartica", $("#kartice").tabs("option","active"))
        },
        active: window.sessionStorage.getItem("selektovana_kartica")
    });

    // back dugme funkcionise u skladu sa selektovanim karticama
    $.address.change(function(event){
         const hashTab = (window.location.hash).match(/#(.*)_tab/)
         const openedTab = (hashTab === null || hashTab.length === 0) ? 0 : hashTab[1]
         $("#kartice").tabs("refresh")
         $("#kartice").tabs("option", "active" , openedTab )
       })

    $('a').click(function(){
       $(this).attr('target', '_blank');
    });


});
