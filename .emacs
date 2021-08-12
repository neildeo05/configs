; Neil's terrible, horrible, super bad emacs configuration
(require 'package)
 
(add-to-list 'package-archives '("org" . "http://orgmode.org/elpa/"))
(add-to-list 'package-archives '("melpa" . "http://melpa.org/packages/"))
(add-to-list 'package-archives '("melpa-stable" . "http://stable.melpa.org/packages/"))
 
(setq package-enable-at-startup nil)
(package-initialize)
(setq backup-directory-alist `(("." . "~/.saves")))

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(company-quickhelp-color-background "#4F4F4F")
 '(company-quickhelp-color-foreground "#DCDCCC")
 '(custom-enabled-themes '(gruvbox-dark-medium))
 '(custom-safe-themes
   '("8f97d5ec8a774485296e366fdde6ff5589cf9e319a584b845b6f7fa788c9fa9a" "a22f40b63f9bc0a69ebc8ba4fbc6b452a4e3f84b80590ba0a92b4ff599e53ad0" "6b2636879127bf6124ce541b1b2824800afc49c6ccd65439d6eb987dbf200c36" "8e797edd9fa9afec181efbfeeebf96aeafbd11b69c4c85fa229bb5b9f7f7e66c" "1436d643b98844555d56c59c74004eb158dc85fc55d2e7205f8d9b8c860e177f" "585942bb24cab2d4b2f74977ac3ba6ddbd888e3776b9d2f993c5704aa8bb4739" "78e9a3e1c519656654044aeb25acb8bec02579508c145b6db158d2cfad87c44e" default))
 '(fci-rule-color "#5B6268")
 '(jdee-db-active-breakpoint-face-colors (cons "#1B2229" "#51afef"))
 '(jdee-db-requested-breakpoint-face-colors (cons "#1B2229" "#98be65"))
 '(jdee-db-spec-breakpoint-face-colors (cons "#1B2229" "#3f444a"))
 '(nrepl-message-colors
   '("#CC9393" "#DFAF8F" "#F0DFAF" "#7F9F7F" "#BFEBBF" "#93E0E3" "#94BFF3" "#DC8CC3"))
 '(package-selected-packages
   '(projectile magit helm-ag doom-themes gruvbox-theme company multiple-cursors zenburn-theme irony helm-swoop smex helm markdown-mode))
 '(pdf-view-midnight-colors '("#DCDCCC" . "#383838"))
 '(vc-annotate-background "#282c34")
 '(vc-annotate-color-map
   (list
    (cons 20 "#98be65")
    (cons 40 "#b4be6c")
    (cons 60 "#d0be73")
    (cons 80 "#ECBE7B")
    (cons 100 "#e6ab6a")
    (cons 120 "#e09859")
    (cons 140 "#da8548")
    (cons 160 "#d38079")
    (cons 180 "#cc7cab")
    (cons 200 "#c678dd")
    (cons 220 "#d974b7")
    (cons 240 "#ec7091")
    (cons 260 "#ff6c6b")
    (cons 280 "#cf6162")
    (cons 300 "#9f585a")
    (cons 320 "#6f4e52")
    (cons 340 "#5B6268")
    (cons 360 "#5B6268")))
 '(vc-annotate-very-old-color nil))

(setq split-width-threshold 1)
;; (custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
;; '(default ((t (:inherit nil :extend nil :stipple nil :background "#3F3F3F" :foreground "#DCDCCC" :inverse-video nil :box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 160 :width normal :foundry "nil" :family "Menlo")))))
 (set-face-attribute 'default nil :height 140)

(defun style-buffer ()
  (interactive)
  (let ((saved-line-number (line-number-at-pos)))
    (shell-command-on-region
     (point-min)
     (point-max)
     "astyle --style=kr --break-return-type --indent=spaces=2 --indent-preproc-define"
     nil
     t)
    (goto-line saved-line-number)))
(global-set-key (kbd "C-x C-o") 'style-buffer)


(defun get-references-of ()
  (interactive)
  (let ((word (thing-at-point 'word 'no-properties)))
    (xref-find-references word)
    ))
(global-set-key (kbd "C-x C-r") 'get-references-of)

(defun get-references-of ()
  (interactive)
  (let ((word (thing-at-point 'word 'no-properties)))
    (xref-find-references word)
    ))
(global-set-key (kbd "C-x C-r") 'get-references-of)

(defun compile-makefile ()
  (interactive)
  (delete-other-windows)
  (compile "make")
  (other-window 1))

(global-set-key (kbd "C-x C-m") 'compile-makefile)

(require 'ansi-color)
(defun colorize-compilation-buffer ()
  (toggle-read-only)
  (ansi-color-apply-on-region compilation-filter-start (point))
  (toggle-read-only))
(add-hook 'compilation-filter-hook 'colorize-compilation-buffer)
;; Editor config
(setq inhibit-startup-screen t)
(tool-bar-mode 0)
(menu-bar-mode 0)
(scroll-bar-mode 0)
(show-paren-mode 1)
(global-display-line-numbers-mode)

;; Multiple Cursors
(require 'multiple-cursors)
(global-set-key (kbd "C->")         'mc/mark-next-like-this)
(global-set-key (kbd "C-<")         'mc/mark-previous-like-this)

;; IDO and Smex
(require 'smex)
(global-set-key (kbd "M-x") 'smex)
(ido-mode 1)

;; Company mode
(require 'company)
(global-company-mode)

(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

;; Yes/No message when trying to kill emacs to reduce the possibility of randomly killing emacs on accident
(setq confirm-kill-emacs #'y-or-n-p)
;; Set transient mark mode to nil, so the selection highlight doesn't interfere with my work  
(setq transient-mark-mode nil)

(global-hl-line-mode +1)

(global-hl-todo-mode)

(setq hl-todo-keyword-faces
      '(("TODO"   . "#FF0000")
        ("NOTE"  . "#00FF00")))

(define-key hl-todo-mode-map (kbd "C-c C-p") 'hl-todo-previous)
(define-key hl-todo-mode-map (kbd "C-c C-n") 'hl-todo-next)

(split-window-horizontally)
