open Reprocessing;

let pi = 4.0 *. atan(1.0);
let circleCount = 3;
let radius = 100;
let rawWindowWidth = 600;
let windowHeight = radius*3;
let windowWidth = rawWindowWidth + (radius * (circleCount - 1)) ;

let setup = (env) => Env.size(~width=windowWidth, ~height=windowHeight, env);

let draw = (_state, env) => {
  Draw.background(Utils.color(~r=199, ~g=217, ~b=229, ~a=255), env);
  let rec drawLoop = (i:int) =>
    if (i < circleCount + 1) {
      Draw.fill(Utils.color(~r=0, ~g=166, ~b=244, ~a=255), env);
      Draw.arc(~center=(rawWindowWidth*i/(circleCount + 1) + (radius)*(i-1), windowHeight/2), ~radx=radius, ~rady=radius, ~start=0., ~stop=2.*.pi, ~isOpen=false, ~isPie=false, env);
      Draw.fill(Utils.color(~r=199, ~g=217, ~b=229, ~a=255), env);
      Draw.arc(~center=(rawWindowWidth*i/(circleCount + 1) + (radius)*(i-1), windowHeight/2), ~radx=radius-20, ~rady=radius-20, ~start=0., ~stop=2.*.pi, ~isOpen=false, ~isPie=false, env);
      drawLoop(i+1);
    };
  drawLoop(1);
};
 /* let i = 1
    switch (i < circleCount + 1) {
    | true => Draw.arc(~center=(rawWindowWidth*i/4 + (radius)*i-1, windowHeight/2), ~radx=radius, ~rady=radius, ~start=0., ~stop=2.*.pi, ~isOpen=false, ~isPie=false, env); loop(i+1);
    | false => exit */

  /* Draw.arc(~center=(rawWindowWidth*1/4, windowHeight/2), ~radx=radius, ~rady=radius, ~start=0., ~stop=2.*.pi, ~isOpen=false, ~isPie=false, env);
  Draw.arc(~center=(rawWindowWidth*2/4+radius, windowHeight/2)), ~radx=radius, ~rady=radius, ~start=0., ~stop=2.*.pi, ~isOpen=false, ~isPie=false, env);
  Draw.arc(~center=(rawWindowWidth*3/4+radius*2, windowHeight/2)), ~radx=radius, ~rady=radius, ~start=0., ~stop=2.*.pi, ~isOpen=false, ~isPie=false, env); */



run(~setup, ~draw, ());
