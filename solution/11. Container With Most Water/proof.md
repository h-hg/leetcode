How to move? Choose $l+1$ or $r-1$?
When $h_l < h_r$, assume that $h_{l+1} = h_{r-1} = h_k,d = r - l -1$

||$l+1$|$r-1$|best choice|
|:-:|:-:|:-:|:-:|
|$h_k<h_l<h_r$|$h_k *d$|$h_k*d$|same|
|$h_l<h_k<h_r$|$h_k *d$|$h_l *d$|$l+1$|
|$h_l<h_r<h_k$|$h_r *d$|$h_l *d$|$l+1$|

The case that $h_l > h_r$is similar to above.

When $h_l = h_r = h$, assume that  $h_{l+1} = h_{r-1} = h_k,d = r - l -1$

||$l+1$|$r-1$|best choice|
|:-:|:-:|:-:|:-:|
|$h_k<h_l=h_r$|$h_k * d$|$h_k*d$|same|
|$h_l=h_r<h_k$|$h *d$|$h *d$|same|